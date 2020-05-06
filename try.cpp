#include <iostream>
 
using namespace std;
 
int func(int &a)
{
    int *p = new int;
    return p;           // 不能返回局部对象的引用
}
 
int main()
{
    int a = 10;
    func(a) = 100;          // 返回非常量引用的函数可以当作左值使用
    cout << a << endl;      // 输出100
    return 0;
}