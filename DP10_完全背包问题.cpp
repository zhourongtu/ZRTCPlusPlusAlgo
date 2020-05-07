#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
/*
完全背包问题：允许重复

不选，选
f[j] = max(f[j], f[j-k*w[j]] + k*v[j])
01背包问题。
改进：



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
    // for(int i=0; i<n; i++){//第i件物品
    //     //弄出新型的一个物品，实现背包问题
    //     for(int k=1; k <= m/w[i]; k++){//买k件物品
    //         for(int j=m; j>=k*w[i]; j--){//此时重量为j
    //             f[j] = max(f[j], f[j-k*w[i]] + k*v[i]);
    //         }
    //     }
    // }
    
    //采用正序能够获得前面的结果（如能够买两个的会利用买1个的结果
    //前者采用倒序是为了保证是不买的结果。
    for(int i=0; i<n; i++){//第i件物品
        //弄出新型的一个物品，实现背包问题
        for(int j=w[i]; j<=m; j++){//此时重量为j
            f[j] = max(f[j], f[j-w[i]] + v[i]);
        }
    }
    cout << f[m];
    return 0;
}
