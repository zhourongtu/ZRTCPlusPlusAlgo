#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//旋转数组最小数字
class Solution{
public:
    int leastNum(vector<int> &nums){
        if(nums.size() == 0)return 0;
        //部分有序，使用二分查找
        int i=0, j=nums.size()-1;
        // while(i < j){//一定是旋转数组（除非相同数字）
        while(nums[i] >= nums[j])//保证该数组为旋转数组,可有可无？
            int mid = (i+j)/2;
            if(i+1 == j){
                // return min(nums[i], nums[j]);
                return nums[j];//后者必定小于前者
            }
            if(nums[i] == nums[j] && nums[i] == nums[mid]){
                int min_num = 0x7FFFFFFF;
                for(int k = i; k<=j; k++){
                    if(nums[k] < min_num){
                        min_num = nums[k];
                    }
                }
                return min_num;
            }
            //开始判断向左边还是向右边
            if(nums[mid] >= nums[i]){//该值位于左侧递增数组，则说明，最小值应该出现在右侧盲点
                i = mid;
            }else if(nums[mid] <= nums[j]){//位于右侧递增数组，那么
                j = mid;
            }
        }
        return nums[i];
    }
    //1.while(nums[i] >= nums[j])-->解决直接有序的问题
    //2.i, j, mid的值全部相等-->防止出现1, 0, 1, 1, 1的情况。
    
};
int main()
{
    vector<int> nums = {0, 1, 1, 1, 1};
    Solution a;
    cout << a.leastNum(nums);
}