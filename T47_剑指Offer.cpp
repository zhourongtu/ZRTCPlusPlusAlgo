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
        do{
            sum = a ^ b;
            carry = (a & b) << 1;//因为不存在cin
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
