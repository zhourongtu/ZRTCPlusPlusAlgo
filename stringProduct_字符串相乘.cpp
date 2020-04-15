#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
std::string product(const string &num1, const string &num2){
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
};
int main()
{
    Solution a;
    cout << a.product("123","1234");
    
}