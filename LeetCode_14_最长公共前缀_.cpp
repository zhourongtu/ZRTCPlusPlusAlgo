class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result;
        if(strs.size() == 0)return result;
        if(strs.size() == 1)return strs[0];
        char temp;
        int index = 0;
        for(index=0; index < strs[0].size(); index++){
            temp = strs[0][index];            
            for(auto &str : strs){
                if(str[index] != temp)return result;
            }
            result.push_back(temp);
        }
        return result;
    }
};