#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//旋转数组最小数字
class Solution{
public:
    int leastNum(vector<int> &nums){
        //部分有序，使用二分查找
        int i=0, j=nums.size()-1;
        while(i < j){
            int mid = (i+j)/2;
            if(i+1 == j){
                return min(nums[i], nums[j]);
            }
            //
            if(nums[mid] >= nums[i]){//位于左侧递增数组
                i = mid;
            }else if(nums[mid] <= nums[j]){//位于右侧递增数组，那么
                j = mid;
            }
        }
        return nums[i];
    }
    
};
int main()
{
    vector<int> nums = {1, 0, 1, 1, 1};
    Solution a;
    cout << a.leastNum(nums);
}