#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool match(const char* str, const char* pattern)
    {
        if(strlen(str) == 0 && strlen(pattern) == 0){
            return true;
        }
        return matchCore(str, pattern, 0, 0);
    }
    bool matchCore(const char *str, const char *pattern, int i, int j){
        int len_str = strlen(str);
        int len_pattern = strlen(pattern);
        if(i == len_str && j == len_pattern){
            return true;
        }
        if(i < len_str && j == len_pattern){
            return false;
        }
        // 出现*
        if(j + 1 < len_pattern && pattern[j+1] == '*'){
            // 如果当前是.或者相同，那么出现三种情况
            // 1.匹配0个。
            // 2.匹配1个。（可继续匹配）
            // 3.本次*匹配结束。
            if((i < len_str && pattern[j] == '.')
              || (i < len_str && pattern[j] == str[i])){
                return matchCore(str, pattern, i, j+2)
                    || matchCore(str, pattern, i+1, j)
                    || matchCore(str, pattern, i+1, j+2);
            }else{// 指向不同，那么直接考虑*匹配结束
                return matchCore(str, pattern, i, j+2);
            }
        }
        // 不是*，正常匹配
        if(i < len_str && (pattern[j] == str[i] || pattern[j] == '.'))
            return matchCore(str, pattern, i+1, j+1);
        return false;
    }
};

int main()
{
    Solution s;
    string a = "";
    string b = ".*";
    cout << s.match(a.c_str(), b.c_str());
    return 0;
}