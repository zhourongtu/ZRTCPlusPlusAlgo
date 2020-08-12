#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*请在这里输入这个程序的功能或者作用*/



int main()
{
    int N;
    cin >> N;
    vector<string> temp(7);
    for(int i=0; i<N; i++){
        for(int j=0; j<7; j++){
            cin >> temp[j];
        }
        // 此时7张牌
        sort(temp.begin(), temp.end(), [](string a, string b){
            return a[1] == b[1] ? a[0] <= b[0] : a[1] < b[1];
        });
        int B=0, T=0, W=0;
        int my_B[10]={0}, my_T[10]={0}, my_W[10]={0};
        int hash[10] = {0};
        for(int i=0; i<7; i++){
            if(temp[i][1] == 'B'){
                my_B[temp[i][0]-'0'] = 1;
            }
            if(temp[i][1] == 'T'){
                my_T[temp[i][0]-'0'] = 1;
            }
            if(temp[i][1] == 'W'){
                my_W[temp[i][0]-'0'] = 1;
            }
            hash[temp[i][0] - '0'] = 1;
        }
        int count = 0;
        for(int i=0; i<10; i++){
            if(hash[i]){
                count++;
            }
        }
        if(count < 7){
            cout << "NO" << endl;
            continue;
        }
        // 查相关的值
        int B_flag = 0, T_flag = 0, W_flag = 0;
        if(B < my_B[1] + my_B[4] + my_B[7]){
            B = my_B[1] + my_B[4] + my_B[7];
            B_flag = 1;
        }
        if(B < my_B[2] + my_B[5] + my_B[8]){
            B = my_B[2] + my_B[5] + my_B[8];
            B_flag = 2;
        }
        if(B < my_B[3] + my_B[6] + my_B[9]){
            B = my_B[3] + my_B[6] + my_B[9];
            B_flag = 3;
        }
        if(T < my_T[1] + my_T[4] + my_T[7]){
            T = my_T[1] + my_T[4] + my_T[7];
            T_flag = 1;
        }
        if(T < my_T[2] + my_T[5] + my_T[8]){
            T = my_T[2] + my_T[5] + my_T[8];
            T_flag = 2;
        }
        if(T < my_T[3] + my_T[6] + my_T[9]){
            T = my_T[3] + my_T[6] + my_T[9];
            T_flag = 3;
        }
        if(W < my_W[1] + my_W[4] + my_W[7]){
            W = my_W[1] + my_W[4] + my_W[7];
            W_flag = 1;
        }
        if(W < my_W[2] + my_W[5] + my_W[8]){
            W = my_W[2] + my_W[5] + my_W[8];
            W_flag = 2;
        }
        if(W < my_W[3] + my_W[6] + my_W[9]){
            W = my_W[3] + my_W[6] + my_W[9];
            W_flag = 3;
        }
        if((B + T + W)==7 && (B_flag != T_flag && B_flag != W_flag && W_flag != T_flag)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

// 七星不靠 147、258、369。不同种类，可少两个。

4
1T 4T 7T 2B 5B 8B 9W
1T 2T 3T 4T 5T 6T 7T
1B 2W 3T 4B 5W 6T 8W
2B 8B 5B 2B 6T 7W 4W


YES
NO
YES
NO