#include <iostream>
#include <string>
using namespace std;
/*
1.删除需要删除的节点-->找到next = pToBedeleted
将后面节点挂在这个节点后面，删除pToBedeleted
-->改进
2.如果有后面节点-->利用后面节点，删除后面节点（自己节点改成后面节点即可）
-->特殊情况，后面无节点-->必须遍历
PS：正好为头节点-->头设置成NULL
*/
struct ListNode{
    int       m_nValue = 555;
    ListNode* m_pNext = NULL;
};
class Solution{
public:
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    if(!pListHead || !pToBeDeleted) return;//空的，没必要删了
    if(pToBeDeleted->m_pNext != NULL){
        //删除后面那个节点
        pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
        delete pToBeDeleted->m_pNext;
    }else if(*pListHead == pToBeDeleted){
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }else{//顺序查找
        ListNode *pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted){
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pToBeDeleted->m_pNext;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
};
int main()
{
    Solution a;
    ListNode *temp = new ListNode;
    temp->m_pNext = new ListNode;
    temp->m_pNext->m_pNext = new ListNode;
    temp->m_nValue = 100;
    temp->m_pNext->m_nValue = 200;
    a.DeleteNode(&temp, temp->m_pNext);
    ListNode *p = temp;
    while(p){
        cout << p->m_nValue << "\t";
        p = p->m_pNext;
    }
}