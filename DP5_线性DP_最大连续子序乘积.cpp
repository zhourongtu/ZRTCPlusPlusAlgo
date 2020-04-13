#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    vector<int> num = {2, 3, -2, 4};
    vector<int> dp1(num.size()), dp2(num.size());
    dp1[0] = num[0]>0?num[0]:0; dp2[0] = num[0]<0?num[0]:0;
    int max_num = dp1[0];
    for(int i=1; i<num.size(); i++){
        if(num[i]>0){
            dp1[i] = dp1[i-1]>0 ? num[i]*dp1[i-1] : num[i];
            dp2[i] = dp2[i-1]<0 ? num[i]*dp2[i-1] : 0;
        }else if(num[i]<0){
            dp1[i] = dp2[i-1]<0 ? num[i]*dp2[i-1] : 0;
            dp2[i] = dp1[i-1]>0 ? num[i]*dp1[i-1] : num[i];
        }else{
            dp1[i] = dp2[i] = 0;
        }
        if(dp1[i] > max_num){
            max_num = dp1[i];
        }
    }
    cout << max_num;
}