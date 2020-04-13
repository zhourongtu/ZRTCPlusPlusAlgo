#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> num = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // vector<int> dp(num.size());
    //优化
    int dp = num[0];
    int max_num = dp;
    for(int i=1; i<num.size(); i++){
        if(dp>0){
            dp = dp+num[i];
        }else{
            dp = num[i];
        }
        if(dp > max_num){
            max_num = dp;
        }
    }
    // dp[0] = num[0];
    // for(int i=1; i<num.size(); i++){
    //     if(dp[i-1] > 0){
    //         dp[i] = dp[i-1] + num[i];
    //     }else{
    //         dp[i] = num[i];
    //     }
    //     if(dp[i] > max_num){
    //         max_num = dp[i];
    //     }
    // }
    cout << max_num;
}