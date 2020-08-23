#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

/*
 * 有效括号-->最深的深度
*/
class Solution{
public:
    int getDepthParentheses(string &str){
        int cnt = 0;
        int result = 0;
        for(auto &c:str){
            if(c=='('){
                cnt++;
            }else{
                cnt--;
            }
            result = max(result, cnt);
        }
        return result;
    }
};
int main()
{

    return 0;
}
