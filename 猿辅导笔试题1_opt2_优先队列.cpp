#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * 题目：选N个课程，每个课程开始和结束时间分别是a, b
 * 问：分身成几个人，可以完美上所有课程？
 * 思路：
 * 1.将所有课程左端点排序。
 * 2.根据贪心，查找出不冲突的区间号，区间个数。
 * 3.去掉这些不冲突的区间号。回到2（因为不需要再次排序）
 *
 * 只通过了%50.
 * 优化点1：vector数组的erase非常消耗大，优化上可以考虑用标记来解决。（优化后没解决）
 * 优化点2：采用list容器，可以降低删除的成本。（重新写代码有点困难，因为操作方式不同）
 * 
*/


struct node
{
    int m_begin_time;
    int m_end_time;
    int m_flag = false;
};

int Compare(const node &a, const node &b){
    return a.m_begin_time == b.m_begin_time ? a.m_end_time < b.m_end_time : a.m_begin_time < b.m_begin_time;
}

int main()
{
    int N;
    cin >> N;
    vector<node> courses(N);
    vector<int> all_count;
    for(int i=0; i<N; i++){
        cin >> courses[i].m_begin_time;
        cin >> courses[i].m_end_time;
    }
    sort(courses.begin(), courses.end(), Compare);
    priority_queue<int, vector<int>, greater<int> > pri_queue;
    for(int i=0; i<N; i++){
        if(pri_queue.empty()){
            pri_queue.push(courses[i].m_end_time);
        }else{
            auto smallest = pri_queue.top();
            if(smallest <= courses[i].m_begin_time){// 无需开一条时间线
                int temp = courses[i].m_end_time;
                pri_queue.pop();
                pri_queue.push(temp);
            }
            else{//开一条新的时间线
                pri_queue.push(courses[i].m_end_time);
            }
        }
    }
    cout << pri_queue.size();
}
