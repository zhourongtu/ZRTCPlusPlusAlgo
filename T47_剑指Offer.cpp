#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
不利用加减乘除实现加法-->门电路类似
*/
class Solution{
public:
    int Add(int a, int b){
        int sum, carry;
        // 本质：将加法看作是进位，进行一个异或的结果获取，直到加上进位后没有进位。
        do{
            sum = a ^ b; // 异或结果，本位的结果
            carry = (a & b) << 1; // 所有的进位
            a = sum; 
            b = carry;
        }while(b != 0); // 没有进位后
        return a;
    }
};
int main()
{
    
    return 0;
}
