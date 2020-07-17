#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct node
{
    int a_i; // 第i种陷的g数
    int b_i; // 做第i种粽子消耗的陷的g数
    int c_i; // 做第i种粽子消耗的面粉的g数
    int d_i; // 做第i种陷获得的实际价值
    int count; // 最大限制
};

vector<node> nums;
int main()
{
    int n, m, c0, d0;
    // n为面粉克数
    cin >> n >> m >> c0 >> d0;
    // c0是只消耗面粉，卖出d0
    nums.resize(m+1);
    // 0指向只消耗面粉
    nums[0].a_i = 0;
    nums[0].b_i = 0;
    nums[0].c_i = c0;
    nums[0].d_i = d0;
    nums[0].count = n/nums[0].c_i; // 最大消耗量
    
    vector<int> a_i(m+1), b_i(m+1), c_i(m+1), d_i(m+1);
    for(int i=1; i<=m; i++){
        cin >> nums[i].a_i;
        cin >> nums[i].b_i;
        cin >> nums[i].c_i;
        cin >> nums[i].d_i;
        // 最大限定数
        nums[i].count = nums[i].a_i/nums[i].b_i;
    }
    // 根据消耗面粉的数量排序
    // 此时为背包问题。一个物品，消耗为c，获利为d，数量限定为count，求获利最大。
    // 转换一下
    int W = n; // 总面粉数
    vector<int> w(m+1), v(m+1), c(m+1);
    for(int i=0; i<m+1; i++){
        w[i] = nums[i].c_i; // 重量-->消耗面粉数
        v[i] = nums[i].d_i; // 价值-->获利
        c[i] = nums[i].count; // 最大可取重量
    }
    vector<int> f(W+1, 0);
    vector<int> f_temp(W+1, 0);
    for(int i=0; i<m+1; i++){
        int up = min(c[i], W/w[i]); // 能够取得该种的上限
        // 问题的核心在于，原数据应该好好的保存下来。每一个k的更新，针对的是原数据
        f_temp.assign(f.begin(), f.end());
        for(int k=1; k<=up; k++){ // 假设做k个指定的陷
            for(int j=W; j>=k*w[i]; j--){
                f_temp[j] = max(f_temp[j], f[j - k*w[i]] + k*v[i]);
            }
        }
        f.assign(f_temp.begin(), f_temp.end());
    }
    cout << f[W];

    return 0;
}
