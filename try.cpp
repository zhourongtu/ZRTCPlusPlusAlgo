#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
丑数：
    只包含2，3，5因子的数为丑数。求从小到大顺序的第1500个丑数。
    1为第一个丑数
*/
class Solution{
public:
    int Min(int a, int b, int c){
        int min_num = (a<b)?a:b;
        min_num = (min_num < c)?min_num:c;
        return min_num;
    }
    int UglyNumber(unsigned int N){
        if(N <= 0)return 0;
        vector<int> uglyArray(N);
        uglyArray[0] = 1;
        int i=1;
        
        auto multi2 = uglyArray.begin();
        auto multi3 = uglyArray.begin();
        auto multi5 = uglyArray.begin();

        while(i < N-1){
            int min_num = Min(*multi2 << 1, (*multi3 << 1 + *multi3), (*multi5 << 2 + *multi5));
            // int min_num = 0;
            uglyArray[i+1] = min_num;
            while((*multi2 << 1) <= min_num)
                multi2++;
            while((*multi3 << 1 + *multi3) <= min_num)
                multi3++;
            while((*multi5 << 2 + *multi5) <= min_num)
                multi5++;
            i++;
        }
        return uglyArray[N-1];
    }
};
int main()
{
    Solution a;
    cout << a.UglyNumber(10);
    return 0;
}
