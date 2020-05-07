#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
01背包+完全背包结合
01背包+完全背包+多重背包
*/
class Solution{
public:
};
int main()
{
    vector<int> w = {5, 4, 10};
    vector<int> v = {6, 3, 9};
    vector<int> c = {1, 2, -1};
    //用C的数量解决背包问题    
    int W = 20;
    vector<int> f(W+1, 0);
    for(int i=0; i<3; i++){
        if(c[i] == -1){//完全背包问题
            for(int j=w[i]; j<=W; j++){//此时重量为j
                f[j] = max(f[j], f[j-w[i]] + v[i]);
            }
        }else if(c[i] == 1){//01背包问题
            for(int j=W; j>=w[i]; j--){//此时重量为j
                f[j] = max(f[j], f[j-w[i]] + v[i]);
            }
        }else{//多重背包问题
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
        
    }
    cout << f[W];
    return 0;
}
