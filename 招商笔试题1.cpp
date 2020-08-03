#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

/*
 * 1.模拟题
 * 老板加密。三位数。
 * 思路：按照数字性处理。
*/


using namespace std;

int convert(int a){
    int result = 0;
    int temp = a/100;
    result = (temp << 8);
    a = a - a/100*100;
    temp = a/10;
    result = result + (temp << 4);
    temp = a%10;
    result = result + temp;
    return result;
}

int my_reverse(int a)
{
    int result = a & 1;

    for(int i=1; i<=11; i++){
        if((a>>i) & 1){
            result = (result<<1) + 1;
        }else{
            result = (result<<1) + 0;
        }
    }
    return result;
}

int main()
{
    int N;
    cin >> N;
    int a;
    for(int i=0; i<N; i++){
        cin >> a;
        if(a == 0){
            cout << 0;
            if(i == N-1)cout << endl;
        }
        int result = convert(a);
        // 逆序一下
        result = my_reverse(result);
        // cout << result;
        // 二进制输出
        int mask = 1;
        int flag = 0;
        for(int i=11; i>=0; i--){
            if((mask << i) & result){
                cout << 1;
                flag = 1;
            }else if(flag){
                cout << 0;
            }
        }
        if(i != N-1)cout << endl;
    }
}

