#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector> 
using namespace std; 
struct node{
    int start=-1, end=-1;
    int money=0;
};
int cmp(node a, node b){
    return a.end < b.end;
}
int main(){
    int N;
    cin >> N;
    vector<node> event(N+1);
    vector<int> opt(N+1);//结果
    for(int i=1; i<=N; i++){
        cin >> event[i].start >> event[i].end >> event[i].money;
    }
    sort(event.begin(), event.end(), cmp);
    //0为哨兵任务
    //得到prev
    vector<int> prev(N+1);
    fill(prev.begin(), prev.begin()+N+1, 0);//初始时假设如果执行这个任务，则前面没有任何任务可以执行
    for(int i=1; i<=N; i++){
        int my_start = event[i].start;//我任务的开始时间
        for(int j=0; j<i; j++){//有可能在我之前开始的任务
            if(my_start >= event[j].end){//我可以在我之前做这个任务
                prev[i] = j;
            }else break;
        }
    }
    //获得结果
    fill(opt.begin(), opt.begin()+N+1, 0);
    opt[0] = 0;
    opt[1] = event[1].money;
    for(int i=2; i<=N; i++){
        opt[i] = max(opt[prev[i]]+event[i].money, opt[i-1]);
    }
    printf("%d", opt[N]);
}
// 输入数据
// 8
// 1 4 5
// 3 5 1
// 0 6 8
// 4 7 4
// 3 8 6
// 5 9 3
// 6 10 2
// 8 11 4