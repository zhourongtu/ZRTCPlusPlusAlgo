class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> pre;
        dfs(target, 0, pre, 0, candidates);
        return result;
    }

    void dfs(int target, int begin, vector<int> &pre, int now_sum, vector<int> &candidates){
        if(now_sum == target){
            result.push_back(pre);
            return;
        }else if(now_sum > target){
            return;
        }
        for(int i=begin; i<candidates.size(); i++){
            pre.push_back(candidates[i]);
            dfs(target, i, pre, now_sum+candidates[i], candidates);
            pre.pop_back();
        }
    }
};