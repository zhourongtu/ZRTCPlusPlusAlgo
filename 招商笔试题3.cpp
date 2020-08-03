#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
// 史莱姆拆分题。
// 特征，拆分n次有n+1个史莱姆。
// 尽可能平均分配，然后相乘获得结果。
// 考虑逆向。

int main()
{
    long long s, m;
    long long t, cur, k, sum;
    bool found = false;
    // 最开始s，希望得到的收益是m。需要分裂几次？
    cin >> s >> m;
    
    int i, j, n;
    // 特点：拆分n次-->有n+1个数。
    for(i = 1; i+1 <= s/2; i++){
        priority_queue<long long, vector<long long>, greater<long long>> q; // 最小堆
        sum = 0; // 和值
        n = i+1; // 拆分i次，有i+1个数。
        k = s%n; // 剩余的值。平均分成n份多出来的值。
        for(j = 0; j<n; j++){
            if(j<k){ // 拆出来的多一分的值。
                q.push(s/n + 1);
            }else{ // 拆出来的n等分正常值。
                q.push(s/n);
            }
        }
        while(q.size() > 1){
            k = q.top();
            q.pop();
            t = q.top();
            q.pop();
            sum += k*t;
            q.push(k+t);
        }
        if(sum >= m){
            found = true;
            break;
        }
    }
    if(!found){
        cout << -1 << endl;
    }else{
        cout << i << endl;
    }
    return 0;
}