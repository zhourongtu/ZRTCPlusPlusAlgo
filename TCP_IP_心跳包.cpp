bool CIUSocket::Send()
{    
    int nSentBytes = 0;    
    int nRet = 0;    
    while(true)    
    {        
        // 客户端向服务端发送心跳包
        nRet = ::send(m_hSocket, m_strSendBuf.c_str(), m_strSendBuf.length(), 0);        
        if(nRet == SOCKET_ERROR)        
        {            
            if(::WSAGetLastError() == WSAEWOULDBLOCK)                
                break;            
            else            
            {                
                LOG_ERROR("Send data error, disconnect server:%s, port:%d.", m_strServer.c_str(), m_nPort);
                Close();                
                return false;            
            }        
        }        
        else if(nRet < 1)        
        {            
            //一旦出现错误就立刻关闭Socket            
            LOG_ERROR("Send data error, disconnect server:%s, port:%d.", m_strServer.c_str(), m_nPort);            
            Close();            
            returnfalse;        
        }        
        m_strSendBuf.erase(0, nRet);        
        if(m_strSendBuf.empty())           
            break;        
        ::Sleep(1);    
    }    
    {        
        //记录一下最近一次发包时间        
        std::lock_guard<std::mutex> guard(m_mutexLastDataTime);        
        m_nLastDataTime = (long)time(NULL);    
    }    
    return true;
}

bool CIUSocket::Recv(){    
    intnRet = 0;    
    charbuff[10 * 1024];    
    while(true)    
    {        
        nRet = ::recv(m_hSocket, buff, 10 * 1024, 0);        
        if(nRet == SOCKET_ERROR)                //一旦出现错误就立刻关闭Socket        
        {            
            if(::WSAGetLastError() == WSAEWOULDBLOCK)                
                break;            
            else            
            {                
                LOG_ERROR("Recv data error, errorNO=%d.", ::WSAGetLastError());                //
                Close();                
                return false;            
            }        
        }        
        else if(nRet < 1)        
        {            
            LOG_ERROR("Recv data error, errorNO=%d.", ::WSAGetLastError());            //
            Close();            
            return false;        
        }        
        m_strRecvBuf.append(buff, nRet);        
        ::Sleep(1);    
    }    
    {        
        std::lock_guard<std::mutex> guard(m_mutexLastDataTime);        //记录一下最近一次收包时间        
        m_nLastDataTime = (long)time(NULL);    
    }    
    return true;
}

void CIUSocket::RecvThreadProc()
{    
    LOG_INFO("Recv data thread start...");    
    int nRet;    //上网方式    
    DWORDdwFlags;    
    BOOLbAlive;    
    while(!m_bStop)    
    {        
        //检测到数据则收数据        
        nRet = CheckReceivedData();        //出错        
        if(nRet == -1)        
        {            
            m_pRecvMsgThread->NotifyNetError();        
        }        
        //无数据        
        else if(nRet == 0)        
        {                      
            longnLastDataTime = 0;            
            {                
                std::lock_guard<std::mutex> guard(m_mutexLastDataTime);                
                nLastDataTime = m_nLastDataTime;            
            }            
            if(m_nHeartbeatInterval > 0)            
            {   //当前系统时间与上一次收发数据包的时间间隔超过了m_nHeartbeatInterval                
                //则发一次心跳包                
                if(time(NULL) - nLastDataTime >= m_nHeartbeatInterval)                    
                    SendHeartbeatPackage();            
            }        
        }        
        //有数据        
        else if(nRet == 1)        
        {            
            if(!Recv())            
            {                
                m_pRecvMsgThread->NotifyNetError();                
                continue;            
            }            
            DecodePackages();        
        }// end if    
    }// end while-loop    
    LOG_INFO("Recv data thread finish...");    
}

/////////////////////////////////////////////////////
void BusinessSession::send(constchar* pData, intdataLength)
{    
    bool sent = TcpSession::send(pData, dataLength);    
    //发送完数据更新下发包时间    
    updateHeartbeatTime();     
}

void BusinessSession::handlePackge(char* pMsg, intmsgLength, bool& closeSession, std::vector<std::string>& vectorResponse)
{    
    //对数据合法性进行校验    
    if(pMsg == NULL || pMsg[0] == 0 || msgLength <= 0 || msgLength > MAX_DATA_LENGTH)    
    {        
        //非法刺探请求，不做任何应答，直接关闭连接        
        closeSession = true;        
        return;    
    }    
    //更新下收包时间    
    updateHeartbeatTime();    
    //省略包处理代码...
}
void BusinessSession::updateHeartbeatTime()
{    
    std::lock_guard<std::mutex> scoped_guard(m_mutexForlastPackageTime);    
    m_lastPackageTime = (int64_t)time(nullptr);
}

boolBusinessSession::doHeartbeatCheck()
{    
    constConfig& cfg = Singleton<Config>::Instance();    
    int64_t now = (int64_t)time(nullptr);    
    std::lock_guard<std::mutex> lock_guard(m_mutexForlastPackageTime);    
    if(now - m_lastPackageTime >= cfg.m_nMaxClientDataInterval)    
    {        
        //心跳包检测，超时，关闭连接        
        LOGE("heartbeat expired, close session");        
        shutdown();        
        return true;    
    }    
    return false;
}
void TcpServer::checkSessionHeartbeat(){    
    int64_t now = (int64_t)time(nullptr);    
    if(now - m_nLastCheckHeartbeatTime >= m_nHeartbeatCheckInterval)    
    {        
        m_spSessionManager->checkSessionHeartbeat();        
        m_nLastCheckHeartbeatTime = (int64_t)time(nullptr);    
    }     

void SessionManager::checkSessionHeartbeat()
{      
    std::lock_guard<std::mutex> scoped_lock(m_mutexForSession);    
    for(constauto& iter : m_mapSessions)    
    {        
        //这里调用 BusinessSession::doHeartbeatCheck()        
        iter.second->doHeartbeatCheck();    
    }     
}
