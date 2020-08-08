#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 可任意增加字符串个数与长度，输出最少增加后，成为回文的字符串。
*/

int judgePra(string str)
{
    if(str.size() < 1)return 0;
    if(str.size() == 1)return 1;
    int i = 0, j = str.size()-1;
    while(i < j){
        if(str[i++] != str[j--]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    string rev_str = str;
    reverse(str.begin(), str.end());

    if(judgePra(str)){
        cout << str;
        return 0;
    }
    for(int i=str.size()-1; i>=1; i--){
        string temp = str + rev_str.substr(i, str.size() - i);
        if(judgePra(temp)){
            cout << temp;
            return 0;
        }
    }
    return 0;
}


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 关门时间。
 * 最短花费时间
*/

long long half = 12*3600;
void print_time(long long seconds){
    long long init_seconds = 8*3600;
    long long final_time = init_seconds + seconds;
    printf("%02ld:%02ld:%02ld", (final_time/3600)%24, (final_time-final_time/3600*3600)/60, final_time%60);
    if(final_time >= half){
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
        vector<long long> dp1(n, 0); // 此人买单张票的最低时间
        vector<long long> dp2(n, 0); // 此人与前面人合买的最低时间
        vector<long long> dp(n, 0); // n个人此时的最少时间
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long i=0; i<n; i++){
            cin >> a[i];
        }
        for(long long i=1; i<n; i++){
            cin >> b[i];
        }
        if(n == 1){
            print_time(a[0]);
            continue;
        }
        // 开始计算时间
        b[0] = b[1];
        dp1[0] = a[0];
        dp2[0] = a[0]; //
        dp[0] = a[0];
        for(long long i=1; i<n; i++){
            dp[i] = min(dp1[i-1] + a[i], dp2[i-1] - a[i-1] + b[i-1]); // 
            dp1[i] = dp[i-1] + a[i]; // 自己单独买
            if(i==1){
                dp2[i] = b[i-1];
            }else{
                dp2[i] = dp[i-2] + b[i-1]; //与前一个人混买
            }
        }
        print_time(dp[n-1]);
    }
    
    return 0;
}

// 1
// 5
// 20 40 30 10 50
// 50 20 10 20
