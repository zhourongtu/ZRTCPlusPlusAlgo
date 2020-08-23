#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;


class Solution {
public:
    void prePermutation(vector<int>& nums) {
        // 1.找到破坏降序的
        int len = nums.size();
        int i = len-2;
        for(; i>=0; i--){
            if(nums[i] >= nums[i+1]){
                break;
            }
        }
        if(i < 0){
            sort(nums.rbegin(), nums.rend());
            return;
        }
        // 2.找到降序中第一个比nums[i]小的值
        int j = len-1;
        for(; j>=i; j--){
            if(nums[j] < nums[i])break;
        }
        // 3.进行交换
        swap(nums[i], nums[j]);
        // 4.i以后进行降序排序
        sort(nums.begin()+i+1, nums.end(), [](int a, int b){return a>b;});
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2};
    s.prePermutation(nums);
    for_each(nums.begin(), nums.end(), [](int a){cout << a << '\t';});
    return 0;
}