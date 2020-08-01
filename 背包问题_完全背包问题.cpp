#include <iostream>
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
                int up = j/C[i]; // 最大允许数量（这里控制了j-k*C[i]的越界情况。
                for(int k=1; k <= up; k++){ // 放入k件 第i个物品。这里k是属于不同情况，所以这里是0~up的所有比较
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*C[i]] + k*V[i]);
                }
            }
        }
        return dp[N][W];
    }
    int MaxValue_Complete_opt1(int W, int N, vector<int> &C, vector<int> &V)
    {
        // 思考方式2:优化空间，逆序？
        vector<int> dp(W+1);
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            for(int j=W; j>=C[i]; j--){ //容量为j的背包
                for(int k=j/C[i]; k>= 1; k--){ // 放入k件物品。逆序更新
                    dp[j] = max(dp[j], dp[j-k*C[i]] + k*V[i]);
                }
            }
        }
        return dp[W];
    }

    int MaxValue_Complete_opt2(int W, int N, vector<int> &C, vector<int> &V)
    {
        // 思考方式2:优化空间，逆序？按单件物品多次更新-->可正序
        vector<int> dp(W+1);
        // 初始化
        for(int i=1; i<=N; i++){// 前i件物品
            int up = W/C[i];
            for(int j=C[i]; j<=W; j++){ //容量为j的背包。后面的多次能够覆盖前面1次（增量式）
                dp[j] = max(dp[j], dp[j-C[i]] + V[i]);
            }
        }
        return dp[W];
    }

    // 考虑优化问题。满足Ci <= Cj && Vi >= Vj-->可以优化。通过O(N^2)
    // 费用大于W的去掉。计算出相同费用中价值最高的那个。用O(N+V)完成该优化。
    
    // 还有一种实现方式。将完全背包问题转换成01背包问题求解。
    // 1.直接拆。2.高效方法-->拆成费用为二进制的那种。2^k*Ci。价值2^k*Vi。可以大大减少个数
};
int main()
{
    int W = 10;
    int N = 5;
    vector<int> C = {0, 3, 5, 7, 1, 8};
    vector<int> V = {0, 8, 2, 6, 2, 10};
    Solution s;
    cout << s.MaxValue_Complete(W, N, C, V) << endl;
    cout << s.MaxValue_Complete_opt1(W, N, C, V) << endl;
    cout << s.MaxValue_Complete_opt2(W, N, C, V) << endl;
    return 0;
}
