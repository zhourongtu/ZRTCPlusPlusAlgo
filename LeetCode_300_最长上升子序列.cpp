class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)return n;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int max_len = 0;
        for(int i=1; i<n; i++){
            int len = 1;
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    len = max(dp[j]+1, len);
                }
            }
            dp[i] = len;
            if(len > max_len){
                max_len = len;
            }
        }
        return max_len;
    }
};