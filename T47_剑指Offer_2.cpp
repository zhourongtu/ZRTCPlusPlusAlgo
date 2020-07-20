#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
不利用加减乘除实现加法-->门电路类似
*/
class Solution{
public:
    int Add(int a, int b, int carry_in){
        int sum, carry;
        int now_bit = 1;
        int result = 0;
        // 一位一位更新
        for(int i=0; i<31; i++){
            sum = (a&now_bit) ^ (b&now_bit) ^ carry_in;//低位
            carry_in = ((a&now_bit) & (b&now_bit) | (a&now_bit) & carry_in | carry_in & (b&now_bit)) << 1;//因为不存在cin
            result = result | sum;
            now_bit = now_bit << 1;
        }
        return result;
    }
};
int main()
{
    Solution s;
    cout << s.Add(1111, 22222, 1);
    return 0;
}
