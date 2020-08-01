#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * dp[i][j]定义为0~i的字符串A与0~j的字符串B，相互转变所需要的次数
 * 编辑距离，操作:插入，删除，替换
 * 如果相等-->dp[i][j] = dp[i-1][j-1]
 * 如果不等-->插入-->dp[i][j-1] + 1
 *        -->删除-->dp[i-1][j] + 1
 *        -->替换-->dp[i-1][j-1] + 1
*/
class Solution{
public:
    int EditNum(string a, string b){
        int lena = a.size(), lenb = b.size();
        vector<vector<int>> dp(lena+1, vector<int>(lenb+1, 0));
        for(int j=1; j<=lenb; j++){
            dp[0][j] = j;
        }
        for(int i=1; i<=lena; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=lena; ++i){
            for(int j=1; j<=lenb; j++){
                if(a[i] == b[j]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i][j] + 1;
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
                    dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
                }
            }
        }
        return dp[lena][lenb];
    }
};
int main()
{
    Solution s;
    cout << s.EditNum("zhourongu", "zhourong");
    return 0;
}
