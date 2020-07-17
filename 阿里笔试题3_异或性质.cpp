#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 输入x。x范围0~2^31-1
 * x^a^b 最大（显然是1111111111111111111111）三十一位
 * 求|a - b|最小的个数。
 * 思路：
 * 本质上:a拿头的1。其他1给b。如果，x的某一位，为1.那么这个位就有两种选择-->00与11.
 * 那么只需要计算1的个数即可。再加上a和b不同。*2
 * 特殊情况：0个1，31个1（全部都是1，此时a和b必须完全相同，去掉本身对称性。
*/

int GetNumOfBits1(int x)
{
    int count1 = 0;
    while(x>0){
        if(x & 1){
            count1++;
        }
        x = x >> 1;
    }
    return count1;
}

int main()
{
    // 本质上是考察x可以用的1的个数。
    int T;
    cin >> T;
    long int x;
    for(int i=0; i<T; i++)
    {
        cin >> x;
        long int temp = 1;
        int my_count1 = GetNumOfBits1(x);
        if(my_count1 > 0 && my_count1 < 31){
            cout << ((temp << my_count1)*2) << endl;
        }else if(my_count1 == 31){
            cout << (temp << 31) << endl;
        }
        else{
            cout << 2 << endl;
        }
    }

    return 0;
}
