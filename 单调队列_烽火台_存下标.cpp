#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
 * 单调队列，烽火台。
*/
class Solution{
public:
    // dp方法
    // 状态转移。dp[i] = min(dp[i-M] ~ dp[i-1]) + cost[i];
    int BeaconTower(int N, int M, vector<int> cost)
    {// N为总烽火台数，M为每M个烽火台需要一个点亮，cost代表点亮烽火台需要的代价
    // +0保证当前
        vector<int> f(N+1, 0);
        // 前面M-1个点亮自己的代价，都是自己（其实第M个也是）
        deque<int> single_queue;
        
        // 维护一个单调递增的栈-->价格最低
        for(int i=1; i<=M; ++i){
            f[i] = cost[i];
            while(!single_queue.empty() && f[single_queue.back()] >= f[i]){
                single_queue.pop_back();
            }
            single_queue.push_back(i);
        }
        // 从第M个开始，（设为i）
        // 代价为 i-M~i-1（因为自己必定点亮）中最小代价+自己代价
        for(int i=M+1; i<=N; ++i){ 
            f[i] = f[single_queue.front()] + cost[i]; // 自己的最小代价
            while(!single_queue.empty() && f[single_queue.back()] >= f[i]){ // 价值大的全部抛弃
                single_queue.pop_back();
            }
            single_queue.push_back(i);
            /*
                这里如果在single_queue中有多个值，更大的值如果在前面的下标，此时没有被pop掉
            */
            // 实际上可以用if
            while(!single_queue.empty() && single_queue.front() < i-M+1) {// 对下一次而言，无效的全部抛弃
                single_queue.pop_front();
            }
        }
        // 统计N-M+1 ~ N的代价
        int ans = 0x7FFFFFFF;
        for(int i = N-M+1; i<=N; ++i){
            ans = min(ans, f[i]);
        }
        // for_each(f.begin(), f.end(), [](int a){cout << "\t" << a;});
        // cout << endl;
        return ans;
    }

};
int main()
{
    int N, M;
    // N = 5; M = 3;
    cin >> N >> M;
    vector<int> cost(N+1);
    cost[0] = 0;
    for(int i=1; i<=N; i++){
        cin >> cost[i];
    }
    // vector<int> cost = {0, 1, 2, 5, 6, 2};
    Solution s;
    cout << s.BeaconTower(N, M, cost);
    return 0;
}
