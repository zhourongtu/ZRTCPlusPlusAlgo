#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 最长回文子串。
 * 使用DP。
 * 定义：dp[i][j] 为 从i到j是否为回文
 * 状态转移 dp[i][j] = dp[i+1][j-1] && (str[i] == str[j]);
 * 初始化：对角线=true
 * 填写方向，从列开始，从上往下填（只需要填半个就可以了，上三角）
 * 
 * 
 * https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-c-by-gpe3dbjds1/
*/
class Solution{
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2)return s;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i=0; i<len; i++){
            dp[i][i] = true;
        }
        int max_len = 0;
        int index_i=0, index_j=0;
        for(int j=1; j<len; j++){
            for(int i=0; i<j; i++){
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }else{
                    if(j - i < 3){ //其实2更好理解一点
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] && j-i+1 > max_len){
                    max_len = j-i+1;
                    index_i = i; index_j = j;
                }
            }
        }
        return s.substr(index_i, index_j-index_i+1);
    }
};
int main()
{
    Solution s;
    cout << s.longestPalindrome("ac");
    return 0;
}
