// 核心要点：利用dfs，每一个dfs获取pos及以前的递增子序列。
// dfs传递给下一个dfs，下一个所构成的递增子序列
// 不同之处：获取到的构成递增子序列的值的位置一定是不同的。 
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        dfs(-1, nums, ans, now);
        return ans;
    }
    void dfs(int pos, vector<int>& nums, vector<vector<int>>& ans, vector<int>& now) {
        map<int, bool> flag;               
        for (int i = pos+1; i < nums.size(); i++) {
            if (!now.empty() && now.back() > nums[i]) continue;
            if (flag.count(nums[i]) != 0) continue;
            now.push_back(nums[i]);
            flag[nums[i]] = true;
            dfs(i, nums, ans, now);
            now.pop_back();   
        }        
        if (now.size() > 1) ans.push_back(now);
    }
};