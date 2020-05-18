#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Bellman_Ford算法
****简单证明****
最短路径树。最短路径树的长度不会超过V（如果存在最短路径的话）

解决带负环的情况。
简单实现一下
测试数据：
4 4 0
0 1 2
1 2 3
1 3 5
2 3 1
*/
struct node{
    int v;
    int dis;  
};
vector<vector<node>> G;
vector<int> dis;
vector<int> inq;
vector<int> num;//顶点的入队次数
int N, M, Start;
bool SPFA(int a){
    fill(inq.begin(), inq.end(), 0);
    fill(num.begin(), num.end(), 0);
    fill(dis.begin(), dis.end(), 0x7FFFFFFF);
    dis[a] = 0;
    queue<int> q;
    q.push(a);
    inq[a] = true;
    num[a]++;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for(int j=0; j<G[u].size(); j++){
            int v = G[u][j].v, l = G[u][j].dis;
            if(dis[u] + l < dis[v]){
                dis[v] = dis[u] + l;
                if(inq[v] == false){
                    q.push(v);
                    num[v]++;
                    inq[v] = true;
                    if(num[v] >= G.size())return false;//到达负环
                }
            }
        }
    }
    return true;
}
int main()
{
    cin >> N >> M >> Start;
    G.resize(N);
    dis.resize(N);
    inq.resize(N);
    num.resize(N);

    for(int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
    }
    cout << SPFA(Start);
    // for_each(dis.begin(), dis.end(), [](int a){cout << a << '\t';});
    return 0;
}
