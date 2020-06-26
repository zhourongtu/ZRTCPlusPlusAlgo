#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution;
Solution* Array[2];
class Solution{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B: public Solution
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }
};

int Sum_Solution2(int n)
{
    Solution a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);
    return value;
}
int main()
{
    cout << Sum_Solution2(5);
    return 0;
}
