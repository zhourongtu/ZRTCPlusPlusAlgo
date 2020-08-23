/*
    方法1：
        1.获取所有匹配的括号的下标
        2.排序
        3.获取最长连续子序列的长度
    方法2：动态规划
        dp[i]定义为以s[i]结尾的最长子序列长度
        s[i] == '('
            dp[i] = 0
        s[i] == ')'
            如果s[i-1] == '('--> dp[i] = dp[i-2] + 2;
            如果s[i-1] == ')'--> 
                s[i-dp[i-1]-1] == '('
                    dp[i] = dp[i-dp[i-1]-1] + 2 + dp[i-dp[i-1]-2]
        
        注意：dp[-1]=0（-->上述代码需要进行一定的越界处理，或者全部向右移动一格
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 0; dp[1] = 0;
        if(s[1] == ')' && s[0] == '(')dp[2] = 2;
        else dp[2] = 0;
        int max_len = dp[2];
        for(int i=2; i<s.size(); i++){
            if(s[i] == '('){
                dp[i+1] = 0;
            }else{
                if(s[i-1] == '('){
                    dp[i+1] = dp[i+1-2] + 2;
                }
                else{// s[i-1] = ')'
                    if(i-dp[i+1-1]-1 >= 0){
                        if(s[i-dp[i+1-1]-1] == '('){
                            dp[i+1] = dp[i+1-1] + 2 + dp[i+1-dp[i+1-1]-2];
                        }
                    }
                }
            }
            if(dp[i+1] > max_len){
                max_len = dp[i+1];
            }
        }
        return max_len;

    }
};