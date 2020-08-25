class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> my_map;
        vector<vector<string>> result;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            my_map[temp].push_back(strs[i]);
        }
        for(auto &my_strs:my_map){
            vector<string> temp_strs;
            for(auto &temp_str:my_strs.second){
                temp_strs.push_back(temp_str);
            }
            result.push_back(temp_strs);
        }
        return result;
        
    }
};