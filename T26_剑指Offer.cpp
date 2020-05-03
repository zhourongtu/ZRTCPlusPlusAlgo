#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
/*
实现ComplexListNode* Clone(ComplexListNode *pHead)
复制一个复杂链表的复制
1.先复制基本结点。再遍历，寻找具有兄弟结点的结点，查找指向的值，再找新的链表的指向的值的结点，再相连。
2.复制基本结点，实现map。对应。遍历第2次，此时具有sib结点的，通过映射实现复制 指针
    空间换时间
3.(1).对每一个结点复制，放在原结点后面。(2).设置复制出来的结点的sib。(3).拆分成两个链表

*/
struct ComplexListNode{
    int              m_nValue;
    ComplexListNode* m_pNext = NULL;
    ComplexListNode* m_pSibling = NULL;
};
class Solution{
public:
    void CloneNodes(ComplexListNode *pHead){
        ComplexListNode *pNode = pHead;
        while(pNode != NULL){
            ComplexListNode *pCloned = new ComplexListNode;
            pCloned->m_nValue = pNode->m_nValue;
            pCloned->m_pNext = pNode->m_pNext;
            pCloned->m_pSibling = NULL;

            pNode->m_pNext = pCloned;
            pNode = pCloned->m_pNext;
        }
    }
    void ConnectSiblingNodes(ComplexListNode *pHead){
        ComplexListNode *pNode = pHead;
        while(pNode != NULL){
            ComplexListNode *pCloned = pNode->m_pNext;
            if(pNode->m_pSibling != NULL){
                pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
            }
            pNode = pCloned->m_pNext;
        }
    }

    ComplexListNode* ReconnectNodes(ComplexListNode *pHead){
        ComplexListNode *pNode = pHead;
        ComplexListNode *pClonedHead = NULL;
        ComplexListNode *pClonedNode = NULL;
        if(pNode != NULL){
            pClonedHead = pClonedNode = pNode->m_pNext;
            pNode->m_pNext = pClonedNode->m_pNext;
            pNode = pNode->m_pNext;
        }
        return pClonedHead;
    }
    ComplexListNode* CopyComplexListNode(ComplexListNode *pHead){
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        ComplexListNode *pCloneHead = ReconnectNodes(pHead);
        return pCloneHead;    
    }
};
int main()
{
    
    return 0;
}
