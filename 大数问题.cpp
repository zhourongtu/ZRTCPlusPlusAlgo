#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
//大数乘法
std::string product(const string num1, const string num2){
    string result(num1.size()+num2.size(), '0');
    for(int i=num1.size()-1; i>=0; i--){
        int carry = 0; 
        //解决num1[i]*xxx问题，存储到result相应位中
        for(int j=num2.size()-1; j>=0; j--){
            //此时num[i]*num[j]在num[i+j+1]位置中
            int temp = (result[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            result[i+j+1] = temp%10 + '0';
            carry = temp/10;
        }
        result[i] += carry;
    }
    size_t startpos = result.find_first_not_of("0");
    if(string::npos != startpos){
        return result.substr(startpos);
    }
    return "0";
}
//大数加法（不含负）
string add(const string num1, const string num2){
    if(num1.size() == 0){
        return num2;
    }else if(num2.size() == 0){
        return num1;
    }
    string result(max(num1.size(), num2.size()) + 1, '0');
    int carry = 0;
    auto x_iter = num1.rbegin();
    auto y_iter = num2.rbegin();
    for(int i=result.size()-1; i>=1; --i){
        int x = x_iter == num1.rend() ? 0 : *x_iter - '0';
        int y = y_iter == num2.rend() ? 0 : *y_iter - '0';
        if(x_iter != num1.rend())x_iter++;
        if(y_iter != num2.rend())y_iter++;
        int sum = x + y + carry;
        result[i] = sum%10 + '0';
        carry = sum/10;
    }
    if(carry){
        result[0] = carry + '0';
    }else{
        result = result.substr(1);
    }
    return result;
}
};
int main()
{
    Solution a;
    cout << "乘法" << a.product("123","1234");
    cout << "加法" << a.add("0", "1");
}