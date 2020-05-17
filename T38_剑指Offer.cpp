#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
数字在排序组中出现的次数
思路：二分查找，一个查找最左边，一个查找最右边
*/
class Solution{
public:
    int FindTimesOfNum(const vector<int> &nums, int target){
        int leftIndex = searchLeft(nums, 0, nums.size()-1, target);
        if(leftIndex < 0)return -1;//代表查找失败
        int rightIndex = searchRight(nums, leftIndex, nums.size()-1, target);//减小查找范围（向右即可）
        return (rightIndex - leftIndex + 1);
    }
    int searchLeft(const vector<int> &nums, int start, int end, int target){
        if(start > end)return -1;
        int mid = (start + end) >> 1;
        if(nums[mid] < target){
            return searchLeft(nums, mid+1, end, target);
        }
        else if(nums[mid] > target) {
            return searchLeft(nums, start, mid-1, target);
        }else{
            if(mid > 0 && nums[mid-1] == nums[mid]){
                return searchLeft(nums, start, mid-1, target);
            }
        }
        return mid;
    }
    int searchRight(const vector<int> &nums, int start, int end, int target){
        if(start > end)return -1;
        int mid = (start + end) >> 1;
        if(nums[mid] < target){
            return searchRight(nums, mid+1, end, target);
        }
        else if(nums[mid] > target) {
            return searchRight(nums, start, mid-1, target);
        }else{
            if(mid < end && nums[mid+1] == nums[mid]){
                return searchRight(nums, mid+1, end, target);
            }
        }
        return mid;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {1,1,3,4,6,6,6,7};
    cout << a.FindTimesOfNum(nums, 1);
    return 0;
}
