#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

/*
 * 定义：f(n, m) 为最后剩下的数
 * f(n, m) = 删掉第一个数后，再进行取数f'(n-1, m)
 * f(n-1, m)处理相应的结果，根据前一个删除的结果，进行反映射-->代表实际删掉的值
*/
class Solution{
public:
    int LastRemaining(unsigned int n, unsigned int m)
    {
        if(n < 1 || m < 1)
            return -1;
        int last = 0;
        // 从 f(1, m) --> f(n, m)
        for(int i=2; i<=n; i++){// n-1次
            last = (last + m) % i;
        }
        return last;
    }
};
int main()
{
    Solution s;
    cout << s.LastRemaining(5, 3);
    return 0;
}
