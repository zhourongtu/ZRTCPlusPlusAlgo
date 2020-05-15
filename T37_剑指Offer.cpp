#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

struct ListNode{
    int m_nKey;
    ListNode* m_pNext = NULL;
};
/*
输入两个链表，找出它们的第一个公共结点。
1.我的想法：利用hash。（因为其地址必定相同）

答案：利用栈
因为最后的结点链表都是相同的
*/

class Solution{
public:
    ListNode* FindFirstCommonOfTwoList(ListNode *L1, ListNode *L2){
        stack<ListNode*> my_stk1, my_stk2;
        ListNode *result = NULL;
        while(L1){
            my_stk1.push(L1);
            L1 = L1->m_pNext;
        }
        while(L2){
            my_stk2.push(L2);
            L2 = L2->m_pNext;
        }
        while(!my_stk1.empty() && !my_stk2.empty() &&  my_stk1.top() == my_stk2.top()){
            result = my_stk1.top();
            my_stk1.pop();
            my_stk2.pop();
        }
        return result;
    }
};

void Insert(ListNode *&a, int value){
    if(a == NULL){
        a = new ListNode;
        a->m_nKey = value;
    }
    else{
        ListNode *pre = a;
        ListNode *tmp = a;
        while(tmp){
            pre = tmp;
            tmp=tmp->m_pNext;
        }
        pre->m_pNext = new ListNode;
        pre->m_pNext->m_nKey = value;
    }
    return;
}
int main()
{
    ListNode* L1 = NULL;
    ListNode* L2 = NULL;
    for(int i=0; i<5; i++){
        Insert(L1, i);
    }
    for(int j=100; j<103; j++){
        Insert(L2, j);
    }
    ListNode *pre, *temp = L2;
    while(temp){
        pre = temp;
        temp = temp->m_pNext;
    }
    pre->m_pNext = L1->m_pNext;

    Solution a;
    cout << a.FindFirstCommonOfTwoList(L1, L2)->m_nKey;
    return 0;
}
