#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 关门时间。
 * 最短花费时间。
 * n个人排队。a[i]代表自己买票所需时间
 * b[i]自己+后面的人买票所需时间
 * // 最短关门所花费时间
*/

long long half = 12*3600;
void print_time(long long seconds){
    long long init_seconds = 8*3600;
    long long final_time = init_seconds + seconds;
    printf("%02ld:%02ld:%02ld", (final_time/3600)%24, (final_time-final_time/3600*3600)/60, final_time%60);
    if(final_time%(24*3600) >= half){
        cout << " pm" << endl;
    }else{
        cout << " am" << endl;
    }
    return;
}
int main()
{
    long long T;
    cin >> T;
    for(long long i=0; i<T; i++){
        long long n;
        cin >> n;
        vector<long long> dp(n, 0); // n个人此时的最少时间
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long i=0; i<n; i++){
            cin >> a[i];
        }
        for(long long i=0; i<n-1; i++){
            cin >> b[i];
        }
        if(n == 1){
            print_time(a[0]);
            continue;
        }
        // 开始计算时间
        dp[0] = a[0];
        dp[1] = min(b[0], a[0] + a[1]);
        for(long long i=2; i<n; i++){
            dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i-1]); // 
        }
        print_time(dp[n-1]);
    }
    
    return 0;
}

// 1
// 5
// 20 40 30 10 50
// 50 20 10 20
