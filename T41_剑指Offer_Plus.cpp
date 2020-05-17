#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
一系列连续的值 = 特定值?
方法1：
    以下这种动态规划性质。

方法2:
    再来一列，为当前和的
    preSum[0] = 0;
    preSum[1] = nums[0];
    ...
    ...
    显然为递增的。再使用双指针
*/
class Solution{
public:
    vector<int> FindSeriesAddToTarget(vector<int> &nums, int target){
        //返回开始与结束
        vector<int> result;
        int i = 0, j = 0;
        int sum = 0;
        while(i <= j && j<nums.size()){
            if(sum == target){
                result.push_back(i);
                result.push_back(j-1);
                return result;
            }else if(sum < target){
                sum += nums[j];
                if(j == nums.size())break;
                j++;
            }else if(sum > target){
                i++;
                sum -= nums[i];
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 20;
    Solution a;
    vector<int> result = a.FindSeriesAddToTarget(nums, target);
    for_each(result.begin(), result.end(), [](int a){cout << a << '\t';});
    return 0;
}
