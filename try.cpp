﻿#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 有N件物品，容量为W的背包。第i件物品的费用为Ci，价值是Vi
 * 物品有无限件
*/
class Solution{
public:
    // 定义F(i, W)。容量为W的背包，前i件物品，能取到的最大价值
    int MaxValue_Complete(int W, int N, vector<int> &C, vector<int> &V)
    {
        // 思考方式1。
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            for(int j=1; j<=W; j++){ //容量为j的背包
                dp[i][j] = dp[i-1][j];
                int up = j/C[i];
                for(int k=1; k <= up; k++){ // 放入k件 第i个物品。这里k是属于不同情况，所以这里是0~up的所有比较
                    dp[i][j] = max(d[i][j], dp[i-1][j-k*C[i]] + k*V[i]);
                }
            }
        }
        return dp[N][W];
    }
    int MaxValue_Complete_opt(int W, int N, vector<int> &C, vector<int> &V)
    {
        // 思考方式2:优化空间，逆序？
        vector<int> dp(W+1);
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            for(int j=W; j>=C[i]; j--){ //容量为j的背包
                for(int k=j/C[i]; k>= 1; k--){ // 放入k件物品
                    dp[j] = max(dp[j], dp[j-k*C[i]] + k*V[i]);
                }
            }
        }
        return dp[W];
    }
};
int main()
{
    int W = 10;
    int N = 5;
    vector<int> C = {0, 3, 5, 7, 1, 8};
    vector<int> V = {0, 8, 2, 6, 2, 10};
    Solution s;
    cout << s.MaxValue_Complete(W, N, C, V) << endl;
    cout << s.MaxValue_Complete_opt(W, N, C, V) << endl;
    return 0;
}
