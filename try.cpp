#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
};
int main()
{
    uint32_t IP = 100;
    std::cout << (1 <<(IP & static_cast<uint32_t>(7)));
    return 0;
}
