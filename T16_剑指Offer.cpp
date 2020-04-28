#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
翻转链表
*/
struct ListNode{
    int         m_nValue = 8;  
    ListNode*   m_pNext = NULL;
};
class Solution{
public:
ListNode* ReverseList(ListNode* pHead){
    if(pHead == NULL)return NULL;
    ListNode *p1, *p2, *next;
    p1 = pHead;
    p2 = p1->m_pNext;
    while(p2){//反转指向
        next = p2->m_pNext;//保存未来
        p2->m_pNext = p1;
        p1 = p2;
        p2 = next;
    }
    pHead->m_pNext = NULL;
    pHead = p1;
    return pHead;
}
};
int main(){
    ListNode *a = new ListNode;
    a->m_nValue = 1;
    Solution temp;
    ListNode *b = temp.ReverseList(a); 
    while(b){
        cout << b->m_nValue << "\t";
        b = b->m_pNext;
    }
    
}