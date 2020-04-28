#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
统计数的二进制中1的个数
*/
class Solution{
public:
    int countOne(int n){
        int flag = 1;
        int count = 0;
        while(flag){
            if(n & flag){
                count++;
            }
            flag <<= 1;
        }
        return count;
    }
    int countOne2(int n){
        //一个数-1-->此时最右边的一个1-->变成0
        //结果 & 减去1的结果-->使得一个1变成0-->count++
        int subOne;
        int count = 0;
        while(n){
            subOne = n - 1;
            n = subOne & n;
            count++;
        }
        return count;
    }
};
int main()
{
    Solution a;
    cout << a.countOne(9) << endl;
    cout << a.countOne2(17);
}