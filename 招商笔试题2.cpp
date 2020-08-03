
#include <iostream>
using namespace std;

// 2.字典序结果的最小。进行判定。
int main()
{
    int N, K;
    cin >> N >> K;
    
    string str;
    str.resize(N);
    if(N >= 2 && K == 1){
        cout << -1;
    }else if(N < K){
        cout << -1;
    }else{
        int rest;
        for(int i=N-1, k=K; i>= N-(K-2); i--, k--){
            str[i] = 'a' - 1 + k; // 放入最大的字符 
        }
        rest = N - (K-2); // sheng xia d zifu shu
        for(int i=0; i<rest; i++){
            if(i & 1){
                str[i] = 'b';
            }else{
                str[i] = 'a';
            }
        }
        cout << str;
    }
    
}