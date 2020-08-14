#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 0~n-1的n个数字排成一个圈，从数字0开始每次从这个圆圈里删除第m个数字。求圆圈里剩下的最后一个数字。
*/
// 模拟？
class Solution{
public:
    int LastRemaining(unsigned int n, unsigned int m)
    {
        if(n < 1)return -1;
        int now = 0;
        for(int i=2; i<=n; i++){
            now = (now + (m-1)%i + 1)%i;
        }
        return now;
        /*
        if(n < 1 || m < 1)
            return -1;
        unsigned int i = 0;
        vector<int> hash(n);
        fill(hash.begin(), hash.end(), 1);
        int currentStep = 0;
        int count = 0; int now = 0;
        while(count < n-1){
            now = 0;
            while(now < m){
                if(hash[currentStep])
                    now++;
                if(now == m){
                    hash[currentStep] = 0;//删掉
                }
                currentStep = (currentStep+1)%n;
            }
            count++;
        }
        for(int i=0; i<n; i++){
            if(hash[i]){
                cout << i;
                return i;
            }
        }
        return -1;
        */
    }
};
int main()
{
    Solution s;
    s.LastRemaining(5, 3);
    return 0;
}
