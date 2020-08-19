#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
};
int main()
{
    srand((int)time(0));
    vector<int> num(100);
    for(int i=0; i<100; i++){
        num[i] = i;
    }
    for(int i=99; i > 0; i--){
        int temp = rand()%i;
        swap(num[i], num[temp]);
    }
    
    for_each(num.begin(), num.end(), [](int a){cout << a << '\t' << endl;});
    return 0;
}
