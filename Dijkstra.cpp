#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
Dijkstra算法
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
vector<int> visit;
int N, M, Start;
void Dijkstra(int a){
    fill(visit.begin(), visit.end(), 0);
    fill(dis.begin(), dis.end(), 0x7FFFFFFF);
    dis[a] = 0;
    for(int i=0; i<G.size(); i++){
        int u = -1, min_dis = 0x7FFFFFFF;
        for(int j=0; j<dis.size(); j++){
            if(visit[j]==0 && dis[j] < min_dis){
                min_dis = dis[j];
                u = j;
            }
        }
        if(u==-1)break;
        visit[u] = 1;
        for(int j=0; j<G[u].size(); j++){
            int des = G[u][j].v, l = G[u][j].dis;
            if(visit[des] == 0 && dis[u] + l < dis[des]){
                dis[des] = dis[u] + l;
            }
        }
    }
}
int main()
{
    cin >> N >> M >> Start;
    G.resize(N);
    dis.resize(N);
    visit.resize(N);

    for(int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
    }
    Dijkstra(Start);
    for_each(dis.begin(), dis.end(), [](int a){cout << a << '\t';});
    return 0;
}
