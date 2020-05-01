#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

/*
剑指OfferT22加强版
条件：栈有最大限制
题目：
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
    bool IsPopOrder(vector<int> pPush, vector<int> pPop, int maxLength){
        //直接性
        if(pPush.size() != pPop.size() || maxLength <= 0)return false;
        using std::stack;
        stack<int> simulStack;
        int now = 0;//当前指示的一个值
        for(int i=0; i<pPop.size(); i++){
            //当前的一个值pPop[i] 与now进行比对
            if(simulStack.size() >= maxLength){
                break;//直接失败
            }
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
    vector<int> pPush = {1 ,2, 3, 4, 5, 6, 7};   
    vector<int> pPop_OK = {7, 6, 5, 4, 3, 2, 1};
    Solution result;
    cout << "7, 6, 5, 4, 3, 2, 1 限制5:" << result.IsPopOrder(pPush, pPop_OK, 5) << endl;
    cout << "7, 6, 5, 4, 3, 2, 1 限制7:" << result.IsPopOrder(pPush, pPop_OK, 7) << endl;   
    return 0;
}
