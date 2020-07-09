#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

/*
 * 2对括号。()() (())
*/
class Solution{
public:
    // 方法1:使用全排列，进行判断。输出
    bool IsValid(std::string str, int n)
    {
        // 错误检查
        stack<char> tmp_s;
        int len = 2*n;
        for(int i=0; i<len; i++){
            if(str[i] == '('){
                tmp_s.push(str[i]);
            }else if(str[i] == ')'){
                if(!tmp_s.empty()){
                    tmp_s.pop();
                }else{
                    return false;
                }
            }
        }
        return true;
    }

    void Permutation(int n)
    {
        int len = n << 1;
        // std::string str = string('(', n) + string(')', n);
        std::string str;
        for(int i=0; i<n; i++){
            str = str+"(";
        }
        for(int i=0; i<n; i++){
            str = str+")";
        }
        PermutationCore(str, 0, len);
        return;
    }

    void PermutationCore(std::string &str, int now, int len)
    {
        if(now == len)
        {
            if(IsValid(str, len >> 1))
            {
                std::cout << str << std::endl;
            }
        }else{
            for(int i=now; i<len; i++){
                swap(str[now], str[i]);
                PermutationCore(str, now+1, len);
                swap(str[now], str[i]);
            }
        }
        return;
    }
    // 方法2: 卡特兰数问题。剩余左括号和右括号的数量来解决。递推向前
    void matchParentheses(int n)
    {
        std::string str;
        matchParenthesesCore(str, n, n);

    }

    void matchParenthesesCore(std::string str, int left_num, int right_num)
    {
        if(left_num == 0 && right_num == 0){
            std::cout << str << endl;
            return ;
        }
        if(left_num == right_num)
        {
            str = str + "(";
            matchParenthesesCore(str, left_num-1, right_num);
        }
        else if(left_num < right_num){// 数量较少
            if(left_num > 0){
                matchParenthesesCore(str + "(", left_num-1, right_num);
                matchParenthesesCore(str + ")", left_num, right_num-1);
            }
            else{
                str = str + ")";
                matchParenthesesCore(str, left_num, right_num-1);
            }
        }
        return ;
    }
};
int main()
{
    Solution s;
    // s.Permutation(2);
    // 测试IsValid
    // std::cout << s.IsValid(")(()", 2);
    
    // 测试全排列
    // s.Permutation(2);
    s.matchParentheses(3);

    return 0;
}
