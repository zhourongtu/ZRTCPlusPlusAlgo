#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
using namespace std;

/*请在这里输入这个程序的功能或者作用*/

class Solution {
public:
    string intToRoman(int num) {
        // 1000 ~3999
        stringstream my_stream;
        while(num >= 1000){
            my_stream << "M";
            num -= 1000;
        }
        // 900~999
        if(num >= 900){
            my_stream << "CM";
            num -= 900;
        }
        // 500~899
        if(num >= 500){
            my_stream << "D";
            num -= 500;
        }
        // 400~499
        if(num >=400){
            my_stream << "CD";
            num -= 400;
        }
        // 100~399
        while(num >= 100){
            my_stream << "C";
            num -= 100;
        }
        // 90~99
        if(num >= 90){
            my_stream << "XC";
            num -= 90;
        }
        // 50~89
        if(num >= 50){
            my_stream << "L";
            num -= 50;
        }
        // 40~50
        if(num >= 40){
            my_stream << "XL";
            num -= 40;
        }
        // 10~39
        while(num >= 10){
            my_stream << "X";
            num -= 10;
        }
        // 9
        if(num >= 9){
            my_stream << "IX";
            num -= 9;
        }
        // 5~8
        if(num >= 5){
            my_stream << "V";
            num -= 5;
        }
        if(num >= 4){
            my_stream << "IV";
            num -= 4;
        }
        while(num >= 1){
            my_stream << "I";
            num -= 1;
        }
        string result;
        my_stream >> result;
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(999);
    return 0;
}