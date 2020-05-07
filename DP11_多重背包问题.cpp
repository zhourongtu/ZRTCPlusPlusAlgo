#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
有N件物品W容量的背包，每一个物品数量为c[i]，第i件物品的重量为w[i]，价值为v[i]
求价值最大。
    M
N
dp[i][j] = 
*/
class Solution{
public:

};
int main()
{
    vector<int> w = {5, 4, 10};
    vector<int> v = {6, 3, 9};
    vector<int> c = {2, 3, 2};
    int W = 20;
    vector<int> f(W+1, 0);
    //倒叙
    // for(int i=0; i<3; i++){
    //     int up = min(c[i], W/w[i]);
    //     for(int k=1; k<=up; k++){
    //         for(int j=W; j>=k*w[i]; j--){
    //             f[j] = max(f[j], f[j - k*w[i]] + k*v[i]);
    //         }
    //     }
    // }
    //正序
    for(int i=0; i<3; i++){
        int up = min(c[i], W/w[i]);
        //先倒序
        for(int j=W; j>=up*w[i]+1; j--){
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
        //后正序
        for(int j=w[i]; j<=up*w[i]; j++){
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
        
    }
    cout << f[W];

    return 0;
}
