// 方法1：排序，合并
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 合并所有重叠的区间...(要不排序吧？)
        // 按照左端点排序
        int n = intervals.size();
        if(n <= 1)return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] == b[0]? a[1] < b[1] : a[0] < b[0];});
        vector<vector<int>> result;
        result.push_back(intervals[0]); // 第一份
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= result.back()[1]){
                if(intervals[i][1] > result.back()[1]){
                    result.back()[1] = intervals[i][1];
                }
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
