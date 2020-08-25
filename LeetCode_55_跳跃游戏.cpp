// 方法1：向前判断，是否某个点可以达。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 
        int n = nums.size();
        vector<int> could(n);
        could[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(could[j] == 1 && (j-i)<=nums[i]){
                    could[i] = 1; break;
                }
            }
        }
        return could[0];
    }
};
// 方法2：贪心
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
