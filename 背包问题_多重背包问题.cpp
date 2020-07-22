#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 有N件物品，容量为W的背包。第i件物品的费用为Ci，价值是Vi
 * 物品有Mi件可以用
*/
class Solution{
public:
    // 定义F(i, W)。容量为W的背包，前i件物品，能取到的最大价值
    int MaxValue_Multi(int W, int N, vector<int> &C, vector<int> &V, vector<int> &M)
    {
        // 思考方式1。
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            for(int j=1; j<=W; j++){ //容量为j的背包
                dp[i][j] = dp[i-1][j];
                int up = min(j/C[i], M[i]); //最多的数目
                for(int k=1; k <= up; k++){ // 
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*C[i]] + k*V[i]);
                }
            }
        }
        return dp[N][W];
    }

    int MaxValue_Multi_opt1(int W, int N, vector<int> &C, vector<int> &V, vector<int> &M)
    {
        // 思考方式2:优化空间，逆序？
        vector<int> dp(W+1, 0);
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            for(int j=W; j>=C[i]; j--){ //容量为j的背包
                for(int k=min(j/C[i], M[i]); k>= 1; k--){ // 放入k件物品。逆序更新
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
    vector<int> M = {0, 1, 3, 2, 4, 1};
    Solution s;
    cout << s.MaxValue_Multi(W, N, C, V, M) << endl;
    cout << s.MaxValue_Multi_opt1(W, N, C, V, M) << endl;
    return 0;
}
