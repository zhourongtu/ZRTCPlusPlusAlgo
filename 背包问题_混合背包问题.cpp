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
    int MaxValue_Blend(int W, int N, vector<int> &C, vector<int> &V, vector<int> &M)
    {
        // 思考方式1。
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            // 多重背包问题
            if(M[i] > 1){
                for(int j=1; j<=W; j++){ //容量为j的背包
                    dp[i][j] = dp[i-1][j];
                    int up = min(j/C[i], M[i]); //最多的数目
                    for(int k=1; k <= up; k++){ // 
                        dp[i][j] = max(dp[i][j], dp[i-1][j-k*C[i]] + k*V[i]);
                    }
                }
            }
            // 01背包问题
            else if(M[i] == 1){
                for(int j=1; j<=W; j++){
                    if(j >= C[i]){ // 可以拿这个
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-C[i]] + V[i]); // 注意，这里都是用的旧值，而不是更新后的新值。原因是新值可能造成多买（买多个，而实际数目只有一个）
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            // 数量为0的问题
            else if(M[i] == 0){
                for(int j=1; j<=W; j++){
                    dp[i][j] = dp[i-1][j];
                }
            }
            // 完全背包问题
            else if(M[i] == -1){
                for(int j=1; j<=W; j++){ //容量为j的背包
                    dp[i][j] = dp[i-1][j];
                    int up = j/C[i];
                    for(int k=1; k <= up; k++){ // 放入k件 第i个物品。这里k是属于不同情况，所以这里是0~up的所有比较
                        dp[i][j] = max(dp[i][j], dp[i-1][j-k*C[i]] + k*V[i]);
                    }
                }
            }
        }
        return dp[N][W];
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
    cout << s.MaxValue_Blend(W, N, C, V, M) << endl;
    return 0;
}
