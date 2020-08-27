class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 异
        unordered_map<char, int> need, window;
        int left=0, right=0;
        int start=0, len=3;
        int valid = 0;
        int n = s.size();
        vector<int> result;
        for(int i=0; i<p.size(); i++){
            need[p[i]]++;
        }
        while(right < n){
            int flag_shrink_c = 0;
            char c = s[right];
            right++;
            window[c]++;
            if(need.count(c)){
                if(window[c] == need[c]){
                    valid++;
                }else if(window[c] == need[c]+1){
                    valid--;
                }
            }
            if(right - left > p.size()){
                char d = s[left];
                window[d]--;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid++;
                    }
                    else if(window[d] < need[d]){
                        valid--;
                    }
                }
                left++;
            }
            if(valid == need.size() && right - left == p.size()){
                result.push_back(left);
            }
        }
        return result;
    }
};