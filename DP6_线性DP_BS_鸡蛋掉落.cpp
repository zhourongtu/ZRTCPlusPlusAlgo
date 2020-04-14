#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
public:
    int superEggDrop(int K, int N){
        vector<vector<int> > dp;
        dp.resize(N+1);
        for(int i=0; i<N+1; i++){
            dp[i].resize(K+1);
            fill(dp[i].begin(), dp[i].end(), 0x7FFFFFFF);
        }
        //初始化
        //0个鸡蛋与一个鸡蛋
        for(int i=0; i<=N; i++){
            dp[i][0]=0;
            if(i!=0){
                dp[i][1]=i;
            }
        }
        //0层楼与1层楼
        for(int i=0; i<=K; i++){
            dp[0][i]=0;
            if(i!=0){
                dp[1][i]=1;
            }
        }
        //进行状态转移
        for(int i=2; i<=N; i++){
            for(int j=2; j<=K; j++){
                for(int k=1; k<=i; k++){
                    dp[i][j] = min(max(dp[k-1][j-1], dp[i-k][j])+1, dp[i][j]);
                }
            }
        }
        return dp[N][K];
    }
};
int main()
{
    Solution a;
    cout << "1, 2:" << a.superEggDrop(1, 2) << endl;
    cout << "2, 6:" << a.superEggDrop(2, 6) << endl;
    cout << "3, 14:" << a.superEggDrop(3, 14) << endl;
}