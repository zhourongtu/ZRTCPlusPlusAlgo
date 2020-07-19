#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s，
输入n，打印出s所有可能出现值的概率
*/
class Solution{
public:
};
int main()
{
    //1.次数一共有6^n次方
    //2.一个数的次数 = 前6个数
    // 按次数分析骰子。
    int n = 4;
    vector<int> v1(n*6+1);
    vector<int> v2(n*6+1);
    int num = pow(6, n);
    int flag = 0;
    fill(v1.begin()+1, v1.begin()+1+6, 1); // 第一个骰子，1~6的次数都是1.
    for(int i=2; i<=n; i++){// 从2~n个骰子
        if(flag==0)// flag = 0，时，数据存储在v1，推导v2。反之...
        {
            for(int j=i; j<=i*6; j++){
                v2[j] = 0; // i~6*i的所有点数都会受到影响，与v1[]的旧情况相关
                for(int k=j<=6?1:j-6; k<j; k++){ // j这个点数与前面六个有关，但如果小于6，则从1开始
                    v2[j] += v1[k];
                }
            }   
            flag = !flag;         
        }
        else{
            for(int j=i; j<=i*6; j++){
                v1[j] = 0;
                for(int k=j<=6?1:j-6; k<j; k++){
                    v1[j] += v2[k];
                }
            }        
            flag = !flag;    
        }
    }
    fill(v1.begin(), v1.begin()+n, 0);
    fill(v2.begin(), v2.begin()+n, 0);
    int count = 0;

    cout << num << endl;
    if(flag==0){
        count = 1;
        for_each(v1.begin()+1, v1.end(), [&num, &count](int a){printf("数%d的概率是%.2f%%\n", count++, a*1.0/num*100);});
    }else{
        count = 1;
        for_each(v2.begin()+1, v2.end(), [&num, &count](int a){printf("数%d的概率是%.2f%%\n", count++, a*1.0/num*100);});
    }

}
