class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1.找到破坏升序的
        int len = nums.size();
        int i = len-1;
        for(; i>=1; i--){
            if(nums[i-1] < nums[i]){
                break;
            }
        }
        if(i == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        // 2.找到升序中第一比nums[i-1]大的值
        int j = len-1;
        for(; j>=i; j--){
            if(nums[j] > nums[i-1])break;
        }
        // 3.进行交换
        swap(nums[i-1], nums[j]);
        // 4.i以后进行升序排序
        sort(nums.begin()+i, nums.end());
    }
};