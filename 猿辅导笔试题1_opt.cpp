#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 题目：选N个课程，每个课程开始和结束时间分别是a, b
 * 问：分身成几个人，可以完美上所有课程？
 * 采用染色的方法
*/


int main()
{
    int N;
    cin >> N;
    vector<int> my_time(1000000, 0);
    int begin, end;
    int max_end = 0;
    for(int i=0; i<N; i++){
        cin >> begin >> end;
        max_end = max(max_end, end);
        for(int j=begin; j<end; j++){
            my_time[j]++;
        }
    }
    int max_count = 0;
    for(int i=0; i<=end; i++){
        max_count = max(max_count, my_time[i]);
    }
    cout << max_count;
    return 0;
}
