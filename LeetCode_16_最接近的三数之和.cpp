class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ptr_i, ptr_j;
        int align = INT_MAX;
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            ptr_i = i+1;
            ptr_j = nums.size()-1;
            while(ptr_i < ptr_j){
                int sum = nums[i] + nums[ptr_i] + nums[ptr_j];
                if(sum > target){
                    ptr_j--;
                    if(sum - target < align){
                        align = sum - target;
                        result = sum;
                    }
                }else if(sum < target){
                    ptr_i++;
                    if(target - sum < align){
                        align = target - sum;
                        result = sum;
                    }
                }else{
                    return target;
                }
            }
        }
        return result;
        
    }
};