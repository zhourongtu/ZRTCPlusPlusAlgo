#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
题目：
抽取N个随机数。第i个数的区间为v[i].left -> v[i].right

N个随机数的最小值的期望。
*/
struct node{
    int left;
    int right;
};
bool cmp(node a, node b){
    return a.left != b.left ? a.left < b.left : a.right < b.right;
}
int main()
{
    int N;
    cin >> N;
    vector<node> v(N);
    //本质是一道数学问题，概率论的问题
    for(int i=0; i<N; i++){
        cin >> v[i].left;
    }
    for(int i=0; i<N; i++){
        cin >> v[i].right;
    }
    //先按左边界进行排序
    sort(v.begin(), v.end(), cmp);
    //排序完成以后
    //取最小的那个区间，保存在v[0]，最小值必定在这个以内
    int pre_r = v[0].right;
    int pre_l = v[0].left;
    int length = pre_r - pre_l + 1;
    double seq[2001] = {0};
    double weight[2001] = {0};
    for(int i=pre_l; i<=pre_r; i++){
        seq[i]=1;
        weight[i]=1;
    }
    //当前权重
    for(int i=1; i<N; i++){
        if(v[i].left <= pre_r){
            //没有出这个区间
            int this_right = min(pre_r, v[i].right);
            //权重计算（如果在这个区间内
            double this_weight = (this_right - v[i].left+1)/(v[i].right - v[i].left+1);//权重占比
            if(v[i].right <= pre_r){//如果该区间事实上更小
                this_weight = 1.0*(pre_r-pre_l+1)/(v[i].right-v[i].left+1);//修改权重大小
            }
            for(int j=v[i].left; j<=this_right; j++){
                seq[j] = seq[j] + 1;
                weight[j] = weight[j] + this_weight;
            }
        }else{
            break;
        }
    }
    double result=0;
    double total = 0;
    for(int i=pre_l; i<=pre_r; i++){
        result = result+1.0*i*seq[i];//加上相应权重
        total = total + weight[i];
    }
    cout << result/total;
}
