#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 有N件物品和一个容量为W的背包，放入第i件物品消耗的费用是Ci，得到的价值是Vi。
 * 求解：将哪些物品装入背包使得总和价值最大
 * 
 * 似乎这里变成了无限物品问题
*/
class Solution{
public:
    // 如何解决这个问题
    // 设dp[n]为容量为n的背包，能够取得的最大价值
    int MaxValue_01(int W, int N, vector<int> &C, vector<int> &V)
    {
        vector<int> dp(N+1, 0);
        for(int i=1; i<=W; i++){
            for(int j=0; j<N; j++){// 观察第j件物品要不要
                if(i >= C[j]){
                    dp[i] = max(dp[i-1], dp[i-C[j]] + V[j]);
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
    vector<int> C = {3, 5, 7, 1, 8};
    vector<int> V = {8, 2, 6, 2, 10};
    Solution s;
    cout << s.MaxValue_01(W, N, C, V);
    return 0;
}
