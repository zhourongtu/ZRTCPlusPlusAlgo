#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
index其实代表剩余个数index+1或者前index+1个
Problem(index, target):
    只有前index+1个时，能够凑到S的个数。
*/
class Solution{
public:
//nums为数据，index为当前处理到的下标，S为目标数
int rec_subset(std::vector<int> &nums, int index, int S){
    //递归出口
    if(S == 0){
        return 1;
    }else if(index == 0){
        return nums[0] == S;
    }else if(nums[index] > S){
        return rec_subset(nums, index-1, S);
    }else{
        return rec_subset(nums, index-1, S) + rec_subset(nums, index-1, S - nums[index]);
    }
}

int dp_subset(std::vector<int> &nums, int S){
    int num_row = nums.size(), num_column = S+1;
    vector<vector<int> > dp;
    dp.resize(num_row);
    for(int i=0; i<num_row; i++){
        dp[i].resize(num_column);
    }
    //初始化:当j==0, dp[i][j] = 1;
    for(int i=0; i<num_row; i++){
        dp[i][0] = 1;
    }
    //当i==0, dp[i][j] = nums[i]==j;
    for(int j=0; j<num_column; j++){
        if(nums[0] == j){
            dp[0][j] = 1;
        }
    }
    dp[0][0]=1;
    //状态转移
    for(int i=1; i<num_row; i++){
        for(int j=1; j<num_column; j++){
            //判断是否有两种状态
            if(nums[i] > j){//太高，不能选
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
            }
        }
    }
    return dp[num_row-1][num_column-1];
}
int dp_subset_opt(std::vector<int> &nums, int S){
    int num_row = nums.size(), num_column = S+1;
    vector<int> dp_last(num_column);
    vector<int> dp_now(num_column);
    //初始化
    dp_last[0] = 1;
    for(int i=1; i<num_column; i++){
        if(nums[0] == i){
            dp_last[i]=1;
        }
    }
    //开始填充 -->还有种优化方法是通过last和now直接切换指向的值即可
    for(int i=1; i<num_row; i++){
        dp_now[0] = 1;
        //对比的是第i个元素
        for(int j=1; j<num_column; j++){
            if(nums[i] > j){
                dp_now[j] = dp_last[j];
            }else{
                dp_now[j] = dp_last[j] + dp_last[j-nums[i]];
            }
        }
        dp_last = dp_now;
    }
    return dp_last[num_column-1];
}
};
int main()
{
    Solution a;
    vector<int> nums = {1, 2, 4, 1, 7, 8, 3};
    int S = 9;
    cout << "递归结果：" << a.rec_subset(nums, nums.size()-1, S) << endl;
    cout << "二维数组结果：" << a.dp_subset(nums, S) << endl;
    cout << "二维数组结果（状态压缩）：" << a.dp_subset_opt(nums, S) << endl;
    // cout << "二维数组优化结果：" << a.dp_subset_opt(nums, S) << endl;
}
