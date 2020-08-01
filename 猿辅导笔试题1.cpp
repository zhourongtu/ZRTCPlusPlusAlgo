#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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

int CountBlock(vector<node> &courses, int depth){
    if(courses.size() == 0){
        return depth;
    }else if(courses.size() == 1){
        return depth + 1;
    }
    vector<int> cluster;
    int start = courses[0].m_begin_time;
    int end = courses[0].m_end_time;
    cluster.push_back(0);
    for(int i=1; i<courses.size(); i++){
        if(courses[i].m_begin_time >= end){
            cluster.push_back(i);
            start = courses[i].m_begin_time;
            end = courses[i].m_end_time;
        }
    }
    for(int i=cluster.size()-1; i>=0; i--){
        courses.erase(courses.begin() + cluster[i]);
    }
    return CountBlock(courses, depth+1);
}

int main()
{
    int N;
    cin >> N;
    vector<node> courses(N);
    for(int i=0; i<N; i++){
        cin >> courses[i].m_begin_time;
        cin >> courses[i].m_end_time;
    }
    sort(courses.begin(), courses.end(), Compare);
    cout << CountBlock(courses, 0);
    return 0;
}
