#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//给定一个三角形，找出自顶向下最小路径和，每一步只能移动到下一行中相邻结点
//    2
//   3 4
//  6 5 7
// 4 1 8 3
int main()
{
    vector<int> tri = {2, 3, 4, 6, 5, 7, 4, 1, 8, 3};
    int level = 4;
    vector<int> dp(tri.size());
    dp[0] = tri[0];
    dp[1] = dp[0]+tri[1]; dp[2] = dp[0]+tri[2];
    int len = 2;
    int pos = 3, pre_pos = 1;
    int minist = 0x7FFFFFFF;
    for(int i=2; i<level; i++){
        dp[pos] = dp[pos-len] + tri[pos];
        dp[pos+len] = dp[pos-1] + tri[pos+len];
        len++;
        for(int j=1; j<len-1; j++){
            dp[pos+j] = min(dp[pre_pos+j-1], dp[pre_pos+j]) + tri[pos+j];
        }
        //最大
        if(i==level-1){
            for(int j=0; j<len; j++){
                minist = min(minist, dp[pos+j]);
            }
        }
        pre_pos = pos;
        pos = pos+len;
    }
    cout << minist;
}