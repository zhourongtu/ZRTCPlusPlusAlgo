#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution{
public:
int FieldSum(std::vector<int> &v)
{
    //一排人，向右看，所有人能看到的人数总和。V记录身高。
    //单调减的栈
    v.push_back(INT_MAX);
    stack<int> st;//记录栈顶元素的位置即可
    int sum=0;
    for(int i=0; i<v.size(); i++){
        if(st.empty() || v[st.top()] > v[i]){//
            st.push(i);
        }else{
            while(!st.empty() && v[st.top()] <= v[i]){
                int top = st.top();
                st.pop();
                //当前处理到第i个，top的这个人可以看到i - top - 1个人
                sum+=(i-top-1);
            }
            st.push(i);
        }
    }
    return sum;
}
};
int main()
{
    Solution a;
    vector<int> people = {10,3,7,4,12};
    cout << a.FieldSum(people);
}