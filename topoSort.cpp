#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
核心要点：入度
1.初始化
2.将入度为0加入队列
3.进行依次拓扑排序（判断入度）
应用：判断是否为有向无环图。
*/
vector<vector<int> > G;
vector<int> inDegree;
int main()
{
    int N, M;
    cin >> N >> M; //顶点数，边数
    //初始化
    G.resize(N);
    inDegree.resize(N); fill(inDegree.begin(), inDegree.end(), 0);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        inDegree[b]++;
    }
    //将入度为0的
    queue<int> q;
    for(int i=0; i<N; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int> sortResult;
    int num=0;//用于判断是否有环
    while(!q.empty()){
        int u = q.front();
        q.pop();
        sortResult.push_back(u);
        //删除所有的边
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];//相邻边
            inDegree[v]--;
            if(inDegree[v]==0){//如果使用邻接表，则在相同条件下，没有先后关系（即1不一定在2前面）
                q.push(v);
            }
        }
        num++;
    }
    if(num!=N){
        cout << "此图是不是DAG（有向无环图）";
    }else{
        for(int i=0; i<sortResult.size(); i++){
            if(i!=0)cout << " ";
            cout << sortResult[i];
        }
    }
}