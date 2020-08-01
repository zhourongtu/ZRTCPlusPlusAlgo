#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * DP[i][j][k]定义为，在前i个物品的条件下，拥有体积j，重量承受能力k的背包，最多能获取多少价值的物品
*/
class Solution{
public:
    MaxPrice_Complete(int N, int V, int W, vector<int> &V_cost, vector<int> &W_cost, vector<int> &Price)
    {
        vector<vector<int>> dp(V+1, vector<int>(W+1, 0));
        // 逆序状态压缩
        for(int k=1; k<=N; k++){// 第k件物品
            for(int i=V; i>=V_cost[k]; i--){
                for(int j=W; j>=W_cost[k]; j--){
                    int max_start = min(i/V_cost[k], j/W_cost[k]);
                    for(int V_k=max_start, W_k=max_start; V_k>=1; V_k--, W_k--){
                        dp[i][j] = max(dp[i][j], dp[i-V_k*V_cost[k]][j-W_k*W_cost[k]] + V_k*Price[k]);
                    }
                }
            }
        }
        return dp[V][W];
    }
};
int main()
{
    int N, V, W; // V是容量，W是质量
    N = 4; V = 5; W = 5;
    vector<int> V_cost = {0, 1, 2, 3, 4};
    vector<int> W_cost = {0, 2, 4, 4, 5};
    // vector<int> Count = {0, 1, 1, 1, 1};
    vector<int> Price = {0, 3, 4, 5, 6};
    Solution s;
    cout << s.MaxPrice_Complete(N, V, W, V_cost, W_cost, Price);
    return 0;
}
