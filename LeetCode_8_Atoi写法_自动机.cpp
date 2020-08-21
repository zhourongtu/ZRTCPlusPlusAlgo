// 采用状态机的一种思考方式
// https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

// 第一步、思考状态-->开始，结束，signed，in_number状态
class Automaton{
private:
    string start = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end" ,"end"}}
    };

    int get_loc(char c){
        if(c == ' '){return 0;} // 空格
        if(c == '+' || c == '-'){return 1;} // +-
        if(c >= '0' && c <= '9'){return 2;} // 数字
        return 3; // 其他
    }

public:
    int sign = 1;
    long long result = 0;
    string state = "start";
    void get(char c){
        state = table[state][get_loc(c)]; // 进行状态转移
        if(state == "in_number"){
            result = result * 10 + c - '0';
            result = sign == 1 ? min(result, (long long)INT32_MAX) : min(result, -(long long)(INT32_MIN)); 
        }else if(state == "signed"){
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution{
public:
    int myAtoi(string s){
        Automaton temp_machine;
        for(auto c : s){
            temp_machine.get(c);
        }
        return temp_machine.result * temp_machine.sign;
    }
};
int main()
{
    Solution s;
    cout << s.my_atoi(" -42");
    return 0;
}
