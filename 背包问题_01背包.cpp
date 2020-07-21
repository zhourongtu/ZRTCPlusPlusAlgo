#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 有N件物品和一个容量为W的背包，放入第i件物品消耗的费用是Ci，得到的价值是Vi。
 * 求解：将哪些物品装入背包使得总和价值最大
*/
class Solution{
public:
    // 如何解决这个问题?
    
    // 1.二维的角度思考。
    // 定义。 状态转移方程。 出口与初始状态。
    // 设F(i, w)表示，前i个物品，放入容量为w的包能获取的最大价值
    int MaxValue_01(int W, int N, vector<int> &C, vector<int> &V)
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        fill(dp[0].begin(), dp[0].end(), 0); 
        for(int i=1; i<=N; i++){
            dp[i][0] = 0; // 没有容量
            for(int j=1; j<=W; j++){
                if(j >= C[i]){ // 可以拿这个
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-C[i]] + V[i]); // 注意，这里都是用的旧值，而不是更新后的新值。原因是新值可能造成多买（买多个，而实际数目只有一个）
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }

    // 优化
    int MaxValue_01_opt(int W, int N, vector<int> &C, vector<int> &V)
    {
        // 这里有一个特点。我们需要的是i-1时候的值，需要避免使用到i的值。
        vector<int> dp(W+1, 0);
        for(int i=1; i<=N; i++){ // N件物品，供选择
            for(int j=W;  j>=C[i]; j--){ // 当有j为容量时，最大价值
                dp[j] = max(dp[j], dp[j - C[i]] + V[i]); //能够购买物品i的情况下
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
    cout << s.MaxValue_01(W, N, C, V) << endl;
    cout << s.MaxValue_01_opt(W, N, C, V) << endl;
    return 0;
}
