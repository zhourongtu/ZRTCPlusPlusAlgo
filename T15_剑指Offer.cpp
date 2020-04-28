#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
题目：输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，
即链表的尾节点是倒数第1个结点。例如一个链表有6个结点，从头结点开始他们的值依次是1、2、3、4、5、6。
*/
struct ListNode{
    int         m_nValue;  
    ListNode*   m_pNext = NULL;
};
class Solution{
public:
ListNode* FindKthToTail(ListNode* pListHead, unsigned k){
    //双指针。第一个指针先跑到第k个，第二个指针开始同步前进
    if(pListHead == NULL || k == 0)return NULL;
    int deep = 1;
    ListNode *p1, *p2;
    p1 = p2 = pListHead;
    while(deep < k && p2->m_pNext){
        deep++;
        p2 = p2->m_pNext;
    }
    if(deep == k){//继续往后操作
        while(p2->m_pNext != NULL){
            p2 = p2->m_pNext;
            p1 = p1->m_pNext;
        }//return p1;
    }else{
        return NULL;
    }
    return p1;
}
};
int main(){
    ListNode *a = new ListNode;
    a->m_pNext = new ListNode;
    a->m_pNext->m_nValue = 1;
    a->m_pNext->m_pNext = new ListNode;
    Solution temp;
    ListNode *b = temp.FindKthToTail(a, 2); 
    cout << b->m_nValue << "\t";
    
}