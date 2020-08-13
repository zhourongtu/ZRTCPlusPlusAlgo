#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。

我的方法：中序遍历取得排序的指针。依次修改。时间复杂度为O(n)，空间复杂度为O(n)
剑指Offer：中序遍历时，返回最大值

核心：用一个二级指针返回双向链表最大的那个结点。
    从逻辑上：二级指针是最大的那个结点，使用时，是当前的最小值。
        对于每一个当前的root结点而言，都需要一个左子树的最大值 或者 父亲结点引来的最大值，
            左子树的最大值-->给自己处理（第二步）
            父亲结点的最大值-->给左子树处理（第一步）
            但是处理到的时候，只是获取了一个最大值，这个最大值要给左子树进行处理。

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

// 不知道这两段代码有什么区别！。

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)return NULL;
        TreeNode *pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, &pLastNodeInList);
        TreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != NULL && pHeadOfList->left != NULL){
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }
    void ConvertNode(TreeNode *pRootOfTree, TreeNode **pLastNodeInList){
        // 明确第一点，pLastNodeInList代表我获取的一个最大值
        // 1.如果我是作为左子树而存在的-->我要进行处理
        // 2.我是作为非最小值存在的-->我需要丢给子树处理，再进行自己处理
        
        // 此时，我需要进行处理
        
        *pLastNodeInList = pRootOfTree;
        // 3.此时，我又获取了一个双向链表,且获取了一个双下链表的最大值
        if(pRootOfTree->right != NULL){
            ConvertNode(pRootOfTree->right, pLastNodeInList);
        }
        
    }
    void ConvertNode(TreeNode *pRootOfTree, TreeNode **pLastNodeInList){
        if(pRootOfTree == NULL)return;
        
        //TreeNode *pCurrent = pRootOfTree;
        if(pRootOfTree->left != NULL){
            ConvertNode(pRootOfTree->left, pLastNodeInList);
        }
        if(*pLastNodeInList != NULL){
            (*pLastNodeInList)->right = pRootOfTree;
        }
        // 此时pLastNodeInList指向最后一个
        pRootOfTree->left = *pLastNodeInList;
        if(*pLastNodeInList != NULL)
            (*pLastNodeInList)->right = pRootOfTree;
        *pLastNodeInList = pRootOfTree;
        if(pRootOfTree->right != NULL){
            ConvertNode(pRootOfTree->right, pLastNodeInList);
        }

    }
    
    
};