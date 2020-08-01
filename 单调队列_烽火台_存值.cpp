#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
 * 单调队列，烽火台。
 * 存值还会存在一个BUG。就是最后的值出现越界变成负数，在最后取值的时候，选择最小值，变成负数，则失败。
*/
class Solution{
public:
    // dp方法
    // 状态转移。dp = min
    int BeaconTower(int N, int M, vector<int> cost)
    {// N为总烽火台数，M为每M个烽火台需要一个点亮，cost代表点亮烽火台需要的代价
    // +0保证当前
        vector<int> f(N+1, 0);
        // 前面M-1个点亮自己的代价，都是自己（其实第M个也是）
        deque<int> single_queue;
        for(int i=1; i<=M; ++i){
            f[i] = cost[i];
            // single_queue.back()
            while(!single_queue.empty() && single_queue.back() > f[i]){
                single_queue.pop_back();
            }
            single_queue.push_back(f[i]);
        }
        for(int i=M+1; i<=N; ++i){
            f[i] = 0x7FFFFFFF;
            f[i] = single_queue.front() + cost[i]; // 自己的最小代价
            while(!single_queue.empty() && single_queue.back() > f[i]){ 
                single_queue.pop_back();
            }
            if(!single_queue.empty() &&  f[i-M] == single_queue.front()){
                single_queue.pop_front();
            }
            single_queue.push_back(f[i]);
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

