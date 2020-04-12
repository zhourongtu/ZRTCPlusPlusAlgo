#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> array={3,-1,6,7,-5,-4,5,6,8};//9个
    vector<int> dp;
    dp.resize(array.size());
    dp[0]=1;
    int max_len = 0;
    for(int i=1; i<dp.size(); i++){
        int num=1;
        for(int j=0; j<i; j++){
            if(array[i] >= array[j]){//不下降
                num = max(num, dp[j]+1);
            }
        }
        dp[i] = num;
        max_len = max(max_len, num);
    }
    for(int i=0; i<dp.size(); i++){
        if(i!=0)cout << " ";
        cout << dp[i];
    }
    cout << endl << "最长长度为：" << max_len;
}