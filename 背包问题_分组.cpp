#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 分组背包问题，每一组的物品只能取一个，否则会冲突
 * N, V, K, Price, V_cost。
*/
class Solution{
public:
    MaxValue_Group(int N, int K, int V, vector<vector<int>> &V_cost, vector<vector<int>> &Price){
        vector<int> dp(V+1, 0);
        for(int k=1; k<=K; k++){// 前k组物品。
            for(int j=V; j>=1; j--){ //容量为j的背包
                for(int i=0; i<V_cost[k].size(); i++){ // 第k组物品的第i个
                    if(j >= V_cost[k][i]){
                        dp[j] = max(dp[j], dp[j-V_cost[k][i]] + Price[k][i]);
                    }
                }
            }
        }
        return dp[V];
    }
};
int main()
{
    int N, K, V;
    N = 6; V = 2;
    K = 3; // 二维的体积，二维的价格
    vector<vector<int>> V_cost;
    V_cost.push_back({});
    V_cost.push_back({0, 2, 1});
    V_cost.push_back({0, 3, 2});
    V_cost.push_back({0, 4, 3});
    vector<vector<int>> Price;
    Price.push_back({});
    Price.push_back({0, 2, 4});
    Price.push_back({0, 5, 1});
    Price.push_back({0, 4, 4});
    Solution s;
    cout << s.MaxValue_Group(N, K, V, V_cost, Price);
    
    return 0;
}
