#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    int FastPow(int a, int n){
        if(n == 0)return 1;
        if(n == 1)return a;
        int flag = n & 0x01;//奇数则为1
        int mid_a = FastPow(a, n>>1);
        int result = mid_a * mid_a;
        if(flag) result*=a;
        return result;
    }
};
int main()
{
    Solution a;
    cout << a.FastPow(5, 3);
    return 0;
}
