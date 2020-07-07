// 1.
// 2.
// 3. 一个数，最接近的数。或者not found
// 根据少希所说应该是从后面开始往前，直到有一个大于号，然后交换
// 4. 

//3
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    string get_closed_num(string num){
        if(num.size() == 1 || num.size() == 0) return "";
        int len = num.size();
        int i = len-2;
        while(i >= 0 && num[i] <= num[i-1]){
            i--;
        }
        if(i >= 0){
            swap(num[i], num[i+1]);
        }
        return num;
    }
};
int main()
{
    Solution s;
    cout << s.get_closed_num("123432432423543676864653");
    return 0;
}
