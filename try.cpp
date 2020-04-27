#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//写一个函数，输入n求斐波那契数列的第n项
class Solution{
public:
    long long Fibonacci(unsigned int n){
        if(n <= 0)return 0;
        if(n <= 2)return 1;
        long long a=1, b=1;
        for(int i=0; i<n-2; i++){
            a = a + b;
            long long temp = a;
            a = b;
            b = temp;
        }
        return b;
    }
};
int main(){
    Solution a;
    cout << a.Fibonacci(5);
}