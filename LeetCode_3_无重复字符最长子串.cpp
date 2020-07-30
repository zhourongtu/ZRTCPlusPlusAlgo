#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 思路：通过哈希表，记录已经存在的字符。
// start做二次扫描，到出现重复的字符（中间去除掉所有哈希已经记录的值）

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        if(s.size() == 1)return 1;
        int max_count = 0;
        int start = 0;
        int hash[256] = {0};
        for(int i=0; i<s.size(); ){
            if(hash[s[i]]){
                max_count = max(max_count, i-start);
                hash[s[i]] = 0;
                while(s[start] != s[i]){
                    hash[s[start]] = 0;
                    ++start;
                }
                hash[s[start]] = 0;
                ++start;
                continue;
            }
            max_count = max(max_count, i-start+1);
            hash[s[i++]] = 1;
        }
        return max_count;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("tmmzuxt");
    
    return 0;
}