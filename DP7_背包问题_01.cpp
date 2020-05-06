#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
/*
01背包问题。模拟成拍卖
当第一件商品出来时，不同的人的容量不同。
有资格买的人，会更新自己的容量。
同时保存了先前人的状态。
f[j]的意义：前i个物品，以j的容量进行挑选，能产生的最大价值。
*/
int main()
{
    int n=3;
    int m = 10;
    vector<int> w={4,5,10};
    vector<int> v={5,3,7};
    vector<int> f(m+1, 0);
    //f[j]为背包容量为j时候，能取得的最大物品价值
    //f[j-v[i]] 选当前物品
    for(int i=0; i<n; i++){//第i件物品
        for(int j=m; j>=w[i]; j--){//此时重量为j
            f[j] = max(f[j], f[j-w[i]] + v[i]);
        }
    }
    cout << f[m];
    return 0;
}
