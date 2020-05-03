#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

我的方法：中序遍历取得排序的指针。依次修改。时间复杂度为O(n)，空间复杂度为O(n)
剑指Offer：中序遍历时，返回最大值
*/
struct BinaryTreeNode{
    int             m_nValue;
    BinaryTreeNode *m_pLeft = NULL;
    BinaryTreeNode *m_pRight = NULL;
};
//中序遍历拿到指针

class Solution{
public:
    void InTravel(BinaryTreeNode *pHead, vector<BinaryTreeNode*> &list){
        if(pHead == NULL)return;
        if(pHead->m_pLeft){
            InTravel(pHead->m_pLeft, list);
        }
        list.push_back(pHead);
        if(pHead->m_pRight){
            InTravel(pHead->m_pRight, list);
        }
    }  
    BinaryTreeNode* Convert(BinaryTreeNode *pHead){
        if(pHead == NULL)return NULL;
        vector<BinaryTreeNode*> list;
        InTravel(pHead ,list);
        list[0]->m_pLeft = NULL;
        list[list.size()-1]->m_pRight = NULL;
        for(int i=0; i < list.size()-1; i++){
            list[i]->m_pRight = list[i+1];
            list[i+1]->m_pLeft = list[i];
        }
        return list[0];
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
        pB = pB->m_pLeft;
        // pB = pB->m_pRight;
    }
    return 0;
}
