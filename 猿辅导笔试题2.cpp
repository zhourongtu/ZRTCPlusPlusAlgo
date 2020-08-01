#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 抽奖活动。
 * 从同学A开始就是一棵树。每一个结点是一个奖券。
 * 其实也可以看成一个图
 * 实际上是树的一条路，找出最长的一条路径。
 * 可以通过BFS或者DFS的方式找到该条路径。
 * 
 * 
 * 出错点：B代表第B行的同学，没注意到。没时间改了。
 * B-1的孩子是i。i代表第i个同学。
 * 
 * 特质：根节点可能不止一个。
*/

int max_price = 0x80000000;
vector<int> price;

// 进入DFS时，给出带上这个结点的值。
int DFS(vector<vector<int>> &G, int now, int now_price)
{
    if(G[now].size() == 0){ // 代表没有孩子了。
        if(max_price < now_price)
            max_price = now_price;
    }
    for(int i=0; i<G[now].size(); i++){
        DFS(G, G[now][i], now_price + price[G[now][i]]);
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> G(N+1);
    price.resize(N+1);
    price[0] = 0; // 根节点没有任何奖励。
    int A, B;
    int root;
    for(int i=1; i<=N; i++){
        cin >> A >> B;
        price[i] = A; // 拿到的奖励值
        if(B == 0){
            root = i;// 找到根。
            G[B].push_back(i); 
        }else{
            G[B-1].push_back(i); // B发给i的
        }
    }
    // 进行DFS遍历
    DFS(G, 0, 0);
    cout << max_price;
}

/*
数据
N-->个数。A, B。B代表第几行是父亲结点。A代表奖励数。
3
2 0
1 2
-1 2
3
*/