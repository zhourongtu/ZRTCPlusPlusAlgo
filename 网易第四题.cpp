https://www.nowcoder.com/discuss/470964?type=post&order=time&pos=&page=1&channel=1013&source_id=search_post

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void DFS(int u);
vector<vector<int> > G;
vector<int> tStamp; // time stamp
vector<int> lowtStamp; //low time stamp
vector<int> stk;
int N, M;
int now_time = 0;
int num_SCC = 0;
int main()
{
    int start;
    cin >> N >> M >> start; //顶点数，边数
    //初始化
    G.resize(N);
    tStamp.resize(N); lowtStamp.resize(N);
    fill(tStamp.begin(), tStamp.end(), 0);
    fill(lowtStamp.begin(), lowtStamp.end(), 0);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    //使用DFS
    DFS(start);
    cout << "强连通分量数：" << num_SCC << endl;
}
void DFS(int u)
{
    //进栈
    stk.push_back(u);
    now_time++;//时间戳
    //打上时间戳
    tStamp[u] = lowtStamp[u] = now_time;
    //遍历
    for(int i=0; i<G[u].size(); i++){
        int v = G[u][i];
        if(tStamp[v]==0){//没有访问过
            DFS(v);
            lowtStamp[u] = min(lowtStamp[u], lowtStamp[v]);
        }else if(find(stk.begin(), stk.end(), v) != stk.end() ){//在栈中且访问过
            lowtStamp[u] = min(lowtStamp[u], lowtStamp[v]);
        }
        //修改最早时间戳
    }
    //访问
    if(lowtStamp[u] == tStamp[u]){//无法回溯到更早以前
        cout << stk.size() * (stk.size()-1) / 2 << endl;
        while(stk.back() != u){
            // cout << stk.back() << " ";
            stk.pop_back();
        }
        // cout << stk.back() << endl;
        stk.pop_back();
        num_SCC++;//强连通分量加1
    }
    return ;
}
//N, M, start
//M行 a, b
// 7 9 0
// 0 1
// 1 2
// 2 3
// 3 1
// 2 4
// 3 4
// 0 5
// 5 6
// 6 0
