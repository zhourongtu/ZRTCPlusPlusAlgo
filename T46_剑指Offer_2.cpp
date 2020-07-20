#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 利用加法实现乘法
*/
class Solution{
public:
};
int main()
{
    int n=100;
    int product1 = n+1;
    int product2 = n;
    int shift_num = 0;
    int result = 0;
    while(product2 > 0){
        if(product2 & 1){
            result = result + (product1 << shift_num);
        }
        product2 = product2 >> 1;
        shift_num++;
    }
    result = result >> 1;
    cout << result;
    return 0;
}
