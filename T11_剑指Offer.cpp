#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
public:
    double Power(double base, int exponent){
        //特点：1.指数为负数时，要对数求倒
        //      -->当0时候不可求倒-->base为0 --> base == 0 && exponent < 0

        //处理错误1：底数为0，且指数为负数
        bool g_InvalidInput = false;
        if(abs(base - 0.0) < __DBL_EPSILON__ && exponent < 0){
            g_InvalidInput = true;
            return 0.0;
        }
        unsigned int absExponent = (unsigned int)(exponent);
        //如果指数为负数，则进行修正
        if(exponent < 0){
            absExponent = (unsigned int)(-exponent);
        }
        //修正后得到结果
        double result = PowerWithUnsignedExponent(base, absExponent);
        //负数修正
        if(exponent < 0){
            result = 1.0/result;
        }
        return result;
    }
private:
    double PowerWithUnsignedExponent(double base, unsigned int exponent){
        // double result = 1.0;
        // for(int i=1; i <= exponent; ++i){
        //     result *= base;
        // }
        // return result;
        //改进-->使用幂级数logn
        if(exponent == 0){
            return 1;
        }
        if(exponent == 1){
            return base;
        }
        //当作偶数处理
        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if(exponent & 0x1 == 1)//奇数
            result *= base;
        return result;
    }
};
int main()
{
    Solution a;
    cout << a.Power(-3, -5);
}