#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 用C++设计一个不能被继承的类
*/
class SealedClass1{
public:
    static SealedClass1* GetInstance()
    {
        return new SealedClass1();
    }
    static void DeleteInstance(SealedClass1* pInstance){
        delete pInstance;
    }
private:
    SealedClass1() {}
    ~SealedClass1() {}
};
// 还有一种方法是虚拟继承
int main()
{
    
    return 0;
}
