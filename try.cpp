#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string a = "acdcadg";
    string b = "dcadcad";
    int dp[510][510];
    fill(dp[0], dp[0]+510*510, 0);
    //初始化已经完成
    int a_len = a.length(), b_len = b.length();
    a.insert(a.begin(), ' ');
    b.insert(b.begin(), ' ');
    for(int i=1; i<=a_len; i++){
        for(int j=1; j<=b_len; j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[2][2];
    cout << dp[a_len][b_len];
}