#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
将问题拆解为三个
1.左子树的最大结点。
2.中间结点。
3.右子树的最小结点。
a)保证返回的是最大结点。1.探寻最大。2.保证最大
*/
struct BinaryTreeNode{
    int             m_nValue;
    BinaryTreeNode *m_pLeft = NULL;
    BinaryTreeNode *m_pRight = NULL;
};
class Solution{
public:
    BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
        BinaryTreeNode *pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, &pLastNodeInList);
        BinaryTreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL){
            pHeadOfList = pHeadOfList->m_pLeft;
        }
        return pHeadOfList;
    }
    
    void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList){
        if(pNode == NULL)return;
        BinaryTreeNode *pCurrent = pNode;
        if(pCurrent->m_pLeft != NULL){
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
        }
        //得到左子树的最大值    本结点指向左子树最大值
        pCurrent->m_pLeft = *pLastNodeInList;
        if(*pLastNodeInList != NULL){//左子树最大-->本结点
            (*pLastNodeInList)->m_pRight = pCurrent;
        }
        *pLastNodeInList = pCurrent;
        if(pCurrent->m_pRight != NULL){//遍历到最大的最关键因素
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);
        }
    }
};
int main()
{
    Solution result;
    BinaryTreeNode *pA, *pB;
    pA = new BinaryTreeNode; pA->m_nValue = 10;
    pA->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_nValue = 6;
        pA->m_pLeft->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_pLeft->m_nValue = 4;
        pA->m_pLeft->m_pRight = new BinaryTreeNode; pA->m_pLeft->m_pRight->m_nValue = 8;
    pA->m_pRight = new BinaryTreeNode; pA->m_pRight->m_nValue = 14;
        pA->m_pRight->m_pLeft = new BinaryTreeNode; pA->m_pRight->m_pLeft->m_nValue = 12;
        pA->m_pRight->m_pRight = new BinaryTreeNode; pA->m_pRight->m_pRight->m_nValue = 16;
    
    pB = result.Convert(pA);
    while(pB){
        cout << pB->m_nValue << '\t';
        // pB = pB->m_pLeft;
        pB = pB->m_pRight;
    }
    return 0;
}
