#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
Bellman_Ford算法
注意：这里是有向图
****简单证明****
最短路径树。最短路径树的长度不会超过V（如果存在最短路径的话）

解决带负环的情况。
简单实现一下
测试数据：
4 4 0
0 1 2
1 2 3
2 3 -1
0 3 5
*/
struct node{
    int v;
    int dis;  
};
vector<vector<node>> G;
vector<int> dis;
vector<int> visit;
int N, M, Start;
bool Bellman_Ford(int a){
    fill(visit.begin(), visit.end(), 0);
    fill(dis.begin(), dis.end(), 0x7FFFFFFF);
    dis[a] = 0;
    for(int k=0; k<G.size()-1; k++){
        for(int i=0; i<G.size(); i++){
            for(int j=0; j<G[i].size(); j++){
                int des = G[i][j].v, l = G[i][j].dis;
                if(dis[i] + l < dis[des]){
                    dis[des] = dis[i] + l;
                }
            }
        }
    }
    //判断负环
    for(int i=0; i<G.size(); i++){
        for(int j=0; j<G[i].size(); j++){
            int des = G[i][j].v;
            int l = G[i][j].dis;
            if(dis[i] + l < dis[des]){
                return false;
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
    visit.resize(N);

    for(int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        // G[b].push_back({a, w});
    }
    cout << Bellman_Ford(Start);
    // for_each(dis.begin(), dis.end(), [](int a){cout << a << '\t';});
    return 0;
}
