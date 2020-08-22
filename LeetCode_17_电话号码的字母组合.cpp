class Solution {
    vector<vector<char>> m_map = {
        vector<char>(),
        vector<char>(),
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return vector<string>();
        result.resize(digits.size());
        ret_result.clear();
        DFS(digits, 0);
        return ret_result;
    }

    void DFS(string &digits, int depth){
        if(depth == result.size()){
            ret_result.push_back(result);
            return;
        }
        int now_index = digits[depth] - '0';
        for(int i=0; i<m_map[now_index].size(); i++){
            result[depth] = m_map[now_index][i];
            DFS(digits, depth+1);
        }
        return;
    }
private:
    string result;
    vector<string> ret_result;
};