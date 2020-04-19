#include <iostream>
#include <vector>
using namespace std;
struct bridgeNode{
    int start;
    int end;
};
void DFS(int u);
//判定无向图的割点，桥
vector<vector<int> > G;
int N, M;
int nowTime=0;
vector<int> dfn, low;
vector<int> fa;
vector<int> cutPoint;
vector<bridgeNode> bridge; 
int main()
{
    cin >> N >> M;
    G.resize(N);
    dfn.resize(N); low.resize(N); fa.resize(N);
    fill(dfn.begin(), dfn.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(fa.begin(), fa.end(), -2);
    //存储图
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //进行dfs
    for(int i=0; i<N; i++){
        if(0==dfn[i]){
            fill(fa.begin(), fa.end(), -2);
            bridge.clear(); cutPoint.clear();
            nowTime = 0;
            fa[i] = -1;
            DFS(i);
            //输出所有割点
            cout << "所有割点：";
            for(int j=0; j<cutPoint.size(); j++){
                if(j!=0)cout << " ";
                cout << cutPoint[j];
            }
            cout << endl;
            //桥
            cout << "所有的桥：";
            for(int j=0; j<bridge.size(); j++){
                if(j!=0)cout << " ";
                cout << bridge[j].start << "-" << bridge[j].end;
            }
            cout << endl;
        }
    }
}
void DFS(int u)
{
    //时间戳更新
    low[u] = dfn[u] = ++nowTime;
    int child = 0;
    //对于所有对应的边,进行深度搜索
    int flag_cutPoint = 0;
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(dfn[v]==0){//没有访问过
            child++; fa[v] = u;
            DFS(v);
            //判断u点是不是割点-->条件1：是root节点，且孩子>=2个
            //                    条件2：不是root节点，low[v] >= dfn[u]无法回溯到更早的时间戳
            if(-1 != fa[u] && low[v] >= dfn[u] && !flag_cutPoint){
                cutPoint.push_back(u);
                flag_cutPoint = 1;
            }
            //判断是不是桥
            if(low[v] > dfn[u]){
                bridge.push_back({u, v});//是桥
            }
            low[u] = min(low[u], low[v]);
        }else{//访问过，则有可能是父节点
            if(v != fa[u]){//非父节点更新时间戳
                low[u] = min(low[u], low[v]);
            }
        }
    }
    //条件1
    if(-1 == fa[u] && child >= 2 && !flag_cutPoint){//只需要判断一次就够（优化）
        cutPoint.push_back(u);//是割点
        flag_cutPoint = 1;
    }
}

// 8 9
// 0 1
// 0 2
// 2 3
// 1 2
// 1 3
// 3 4
// 4 6
// 4 7
// 5 7