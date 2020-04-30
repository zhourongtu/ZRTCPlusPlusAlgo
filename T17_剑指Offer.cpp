#include <iostream>
using namespace std;
/*
合并链表
*/
struct ListNode{
    int m_nValue;
    ListNode* m_pNext = NULL;
};

class Solution{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL)return pHead2;
        if(pHead2 == NULL)return pHead1;
        //先取第一个结点
        ListNode *pHead, *p, *tail;
        pHead = new ListNode;
        if(pHead1->m_nValue < pHead2->m_nValue){
            pHead->m_nValue = pHead1->m_nValue;
            pHead1 = pHead1->m_pNext;
        }else{
            pHead->m_nValue = pHead2->m_nValue;
            pHead2 = pHead2->m_pNext;
        }
        tail = pHead;
        while(pHead1 && pHead2){
            p = new ListNode;
            if(pHead1->m_nValue < pHead2->m_nValue){
                p->m_nValue = pHead1->m_nValue;
                pHead1 = pHead1->m_pNext;
            }else{
                p->m_nValue = pHead2->m_nValue;
                pHead2 = pHead2->m_pNext;
            }
            tail->m_pNext = p;
            tail = tail->m_pNext;
        }
        while(pHead1){
            p = new ListNode;
            p->m_nValue = pHead1->m_nValue;
            pHead1 = pHead1->m_pNext;
        }
        while(pHead2){
            p = new ListNode;
            p->m_nValue = pHead2->m_nValue;
            pHead2 = pHead2->m_pNext;
            tail->m_pNext = p;
            tail = tail->m_pNext;
        }
        return pHead;
    }
};

int main()
{
    ListNode *a = new ListNode; a->m_nValue = 1;
    a->m_pNext = new ListNode; a->m_pNext->m_nValue = 3;
    ListNode *b = new ListNode; b->m_nValue = 2;
    b->m_pNext = new ListNode; b->m_pNext->m_nValue = 4;
    Solution solve;
    ListNode* pHead = solve.Merge(a, b);
    while(pHead){
        cout << pHead->m_nValue << "\t";
        pHead = pHead->m_pNext;
    }
}