#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 1+2+...+n计算。
 * 此处采用构造函数求解。构造一次增加相应的值。
*/
class Solution{
public:
    Solution(){     ++N; Sum += N;}
    static void Reset(){    N=0; Sum=0; }
    static unsigned int GetSum(){   return Sum; }
private:
    static unsigned int N;
    static unsigned int Sum; 
};
unsigned int Solution::N = 0;
unsigned int Solution::Sum = 0;
unsigned int Sum_Solution1(unsigned int n)
{
    Solution::Reset();
    Solution *a = new Solution[n];
    delete []a;
    a = NULL;
    return Solution::GetSum();
}
int main()
{
    cout << Sum_Solution1(100);
    return 0;
}
