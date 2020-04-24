/*
输入链表头节点，从头到尾反过来打印每一个节点的值
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ListNode{
    int m_nValue;
    ListNode* m_pNext = NULL;
};
void PrintListReversingly_Recursively(ListNode* pHead);
int main(){
    ListNode a, b;
    a.m_pNext = &b;
    a.m_nValue = 1;
    b.m_nValue = 2;
    PrintListReversingly_Recursively(&a);
}
void PrintListReversingly_Recursively(ListNode* pHead){
    if(pHead != NULL){
        if(pHead->m_pNext != NULL){
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}
