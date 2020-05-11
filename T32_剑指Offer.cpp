#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
从1~n整数中1出现的次数
：排列组合
与PAT49联动：Counting Ones。
那个更简洁：这里是以字符串描述的，那个以数字描述
答案：以单个数字递归描述的。
    第一个数字>1,1,0。
    左边一次只处理一个数。
*/
class Solution{
public:
    int NumberOf1Between1AndN(string &N){
        if(N.empty()) return 0;
        if(N.size() == 1){
            return N[0] >= '1' ? 1 : 0;
        }
        int result = 0;
        //先去掉前导的0
        string str = N.substr(N.find_first_not_of('0'));
        int length = str.size();
        int left, right, now;
        for(int i=0; i<length; i++){
            //i代表前面的个数
            if(i==0)left = 0;
            else left = atoi(str.substr(0, i).c_str());
            if(i == length-1)right = 0;
            else right = atoi(str.substr(i+1).c_str());
            now = str[i] - '0';
            if(now == 0){
                result += left * pow(10, length - i - 1);
            }else if(now == 1){
                result += left * pow(10, length - i - 1);
                result += right + 1;
            }else{
                result += (left+1) * pow(10, length - i - 1);
            }
        }
        return result;
    }
};
int main()
{
    Solution a;
    string str;
    cin >> str;
    cout << a.NumberOf1Between1AndN(str);
    return 0;
}
