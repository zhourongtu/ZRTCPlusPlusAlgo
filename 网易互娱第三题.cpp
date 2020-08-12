#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * 自身耗时计算
*/
struct node{
    int t;
    int e;
    int s;
    int my_time = -1;
};


vector<node> my_nodes;

int rec_deal(int start, int end)
{
    if(start > end)return 0;
    if(start+1 == end){
        return my_nodes[end].t - my_nodes[start].t;// 本件事情的时间
    }
    int solved_time = my_nodes[end].t - my_nodes[start].t;
    // 子应该从start+1，到end-1
    start = start+1; end = end-1;
    int start_id = my_nodes[start].e;
    for(int i=start+1; i<=end; i++){
        // 查找对应的1
        if(my_nodes[i].e == start_id && my_nodes[i].s == 1){
            int result_time = rec_deal(start, i); // 计算start到i，这样一个值所代表的大小
            my_nodes[start].my_time = result_time;
            my_nodes[i].my_time = result_time;
            // solved_time = solved_time - result_time; // 减去下一层子事件的时间
            solved_time = solved_time - (my_nodes[i].t - my_nodes[start].t); // 减去下一层子事件的时间
            i++;
            if(i > end)break;
            start = i;
            start_id = my_nodes[i].e;
        }
    }
    return solved_time;
}

int compare(node &a, node &b){
    return a.my_time == b.my_time ? a.e < b.e : a.my_time > b.my_time;
}

int main()
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        my_nodes.clear();
        int N;
        cin >> N;
        for(int i=0; i<N; i++){
            int t, e, s;
            cin >> t >> e >> s;
            my_nodes.push_back({t, e, s, -1});
        }
        // 进行递归处理
        // 第一层
        int start_id = my_nodes[0].e;
        int start = 0, end;
        for(int i=1; i<N; i++){
            // 查找对应的1
            if(my_nodes[i].e == start_id && my_nodes[i].s == 1){
                int result_time = rec_deal(start, i); // 计算start到i，这样一个值所代表的大小
                my_nodes[start].my_time = result_time;
                my_nodes[i].my_time = result_time;
                i++;
                if(i >= N)break;
                start = i;
                start_id = my_nodes[i].e;
            }
        }
        sort(my_nodes.begin(), my_nodes.end(), compare);
        cout << my_nodes[0].e << endl;
    }
    return 0;
}

// 1
// 8
// 1 1 0
// 5 2 0
// 10 3 0
// 20 3 1
// 25 4 0 
// 40 4 1
// 1000 2 1
// 2000 1 1