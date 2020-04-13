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
int minimalTotal(vector<vector<int> > &tri);
int main()
{
    vector<vector<int> > tri;
    tri.resize(4);
    for(int i=0; i<4; i++){
        tri[i].resize(i+1);
    }
    tri[0][0] = 2;
    tri[1][0] = 3; tri[1][1] = 4;
    tri[2][0] = 6; tri[2][1] = 5; tri[2][2] = 7;
    tri[3][0] = 5; tri[3][1] = 1; tri[3][2] = 8; tri[3][3] = 3;
    //获得最小路径和
    cout << minimalTotal(tri);
}
int minimalTotal(vector<vector<int> > &tri){
    vector<int> dp(tri.size()+2);//最后一层的长度
    fill(dp.begin(), dp.end(), 0);
    for(int i=tri.size()-1; i>=0; i--){//最后一层开始
        for(int j=0; j<i+1; j++){
            dp[j] = min(dp[j], dp[j+1]) + tri[i][j];
        }
    }
    return dp[0];
}