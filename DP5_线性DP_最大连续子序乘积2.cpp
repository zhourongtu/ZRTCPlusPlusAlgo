#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    vector<int> num = {2, 3, -2, 4};
    int max_num = -0x80000000;
    int imax = 1, imin = 1;
    for(int i=0; i<num.size(); i++){
        if(num[i] < 0){
            int tmp = imax;
            imax = imin;
            imin = tmp;
        }
        imax = max(imax*num[i], num[i]);
        imin = min(imin*num[i], num[i]);

        max_num = max(max_num, imax);
    }
    cout << max_num;
}