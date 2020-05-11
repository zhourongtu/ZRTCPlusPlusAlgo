#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:    
    int NumberOf1Between1AndN(int N){
        int a = 1, ans = 0;
        int left, now, right;
        //从右到左
        while(N/a != 0){
            left = N/(a*10);
            now = N/a%10;
            right = N%a;
            if(now == 0){
                ans += left*a;
            }else if(now == 1){
                ans += left*a + right + 1;
            }else{
                ans += (left+1)*a;
            }
            a*=10;
        }
        return ans;
    }
};
int main()
{
    Solution a;
    int n;
    cin >> n;
    cout << a.NumberOf1Between1AndN(n);
    return 0;
}
