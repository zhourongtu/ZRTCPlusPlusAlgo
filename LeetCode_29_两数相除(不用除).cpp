#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1 || divisor == -1){
            if(divisor == -1){
                if(dividend == INT_MIN)return INT_MAX;
            }
        }
        int neg_flag = 1;
        long long long_dividend = dividend, long_divisor = divisor;
        if(long_dividend < 0 && long_divisor > 0 || long_dividend > 0 && long_divisor < 0){
            neg_flag = -1;
        }
        if(long_dividend < 0){
            long_dividend = -long_dividend;
        }
        if(long_divisor < 0){
            long_divisor = -long_divisor;
        }
        long long result = 0;
        long long mask = 1;
        mask <<= 31;
        long long my_dividend = 0;
        for(int i=0; i<32; i++){
            // 循环左移动
            my_dividend <<= 1;
            result <<= 1;
            if(long_dividend & mask){
                my_dividend += 1;
            }

            if(my_dividend >= long_divisor){
                my_dividend -= long_divisor;
                result += 1;
            }
            mask = mask >> 1;
        }
        if(neg_flag == -1){
            return -result;
        }
        return result;
    }
};


int main()
{
    Solution s;
    cout << s.divide(10, 3);
    return 0;
}
