#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
    int ia[6] = {27, 210, 12, 47, 109, 83};
    // vector是容器。allocator是分配器
    vector<int, allocator<int>> vi(ia, ia+6);
    // count_if是算法。vi.begin()与vi.end()是迭代器，可以看成泛化指针。
    // less<int>()是函数体，bind2nd是函数适配器。
    // not1是函数适配器。
    cout << count_if(vi.begin(), vi.end(), 
            not1(bind2nd(less<int>(), 40)));
    // 上面not1...函数称作 predicate，谓词。
    return 0;
}
