#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

/*
输入两个整数序列，第一个表示栈的压入顺序。
判断第二个是不是弹出顺序。

1.以第一个序列建立一个栈。
2.以第二个序列为可出栈的值。
3.当可以出栈时，全部出栈。
4.若栈不为空：第一个序列无法以第二个序列的顺序出栈。
思路：第二个序列的顺序按栈进行排序。以第二个序列为样本，判断可出栈的第一个序列。

加强版：PAT_51题。添加限制条件：栈最大为多少。
*/
class Solution{
public:
    bool IsPopOrder(vector<int> pPush, vector<int> pPop){
        //直接性
        if(pPush.size() != pPop.size())return false;
        using std::stack;
        stack<int> simulStack;
        int now = 0;//当前指示的一个值
        for(int i=0; i<pPop.size(); i++){
            //当前的一个值pPop[i] 与now进行比对
            simulStack.push(pPush[i]);
            while(!simulStack.empty() && simulStack.top() == pPop[now]){
                simulStack.pop();
                now++;//指示下一个值
            }
        }
        if(simulStack.empty()){
            return true;
        }else return false;
    }
};
int main()
{
    vector<int> pPush = {1,2,3, 4, 5};   
    vector<int> pPop_OK = {4, 5, 3, 2, 1};
    vector<int> pPop_No = {4, 3, 5, 1, 2};
    Solution result;
    cout << "4, 5, 3, 2, 1:" << result.IsPopOrder(pPush, pPop_OK) << endl;
    cout << "4, 3, 5, 1, 2:" << result.IsPopOrder(pPush, pPop_No) << endl;   
    return 0;
}
