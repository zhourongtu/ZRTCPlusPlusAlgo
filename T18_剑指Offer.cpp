#include <iostream>

// 输入两棵二叉树，判断B是不是A的子结构
/*
思路：出口：至少有一方为空结点了
1.出现空结点。全空True
2.B空。True
3.A空。False

判断1.
    A的根 = B的根结点
    递归左边&&右边 || ！！！递归（A左，B） || （A右，B）！！！
    ！！！！！如果恰好结点相同怎么办？
判断2.
    A的根 != B的根结点
    递归（A左，B） || （A右，B）



     A              B
     8              8
 8       7       9     2
9   2
   4 7 
*/
struct BinaryTreeNode{
    int         m_nValue;
    BinaryTreeNode* m_pLeft = NULL;
    BinaryTreeNode* m_pRight = NULL;
};

class Solution{
public:
    bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
        //如何判断？
        if(pRoot1 == NULL && pRoot2 == NULL)return true;
        else if(pRoot2 == NULL)return true;
        else if(pRoot1 == NULL)return false;
        if(pRoot1->m_nValue != pRoot2->m_nValue){
            return HasSubTree(pRoot1->m_pLeft, pRoot2) || HasSubTree(pRoot1->m_pRight, pRoot2);
        }else{
            return (HasSubTree(pRoot1->m_pLeft, pRoot2->m_pLeft) && HasSubTree(pRoot1->m_pRight, pRoot2->m_pRight)) 
            || HasSubTree(pRoot1->m_pLeft, pRoot2) || HasSubTree(pRoot1->m_pRight, pRoot2);
        }
    }
};

int main(){
    //构造树。。。。
    BinaryTreeNode *pA, *pB;
    pA = new BinaryTreeNode; pA->m_nValue = 8;
    pA->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_nValue = 8;
        pA->m_pLeft->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_pLeft->m_nValue = 9;
        pA->m_pLeft->m_pRight = new BinaryTreeNode; pA->m_pLeft->m_pRight->m_nValue = 2;
            pA->m_pLeft->m_pRight->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_pRight->m_pLeft->m_nValue = 4;
    pA->m_pRight = new BinaryTreeNode; pA->m_pRight->m_nValue = 7;
    pB = new BinaryTreeNode; pB->m_nValue = 8;
    pB->m_pLeft = new BinaryTreeNode; pB->m_pLeft->m_nValue = 9;
    pB->m_pRight = new BinaryTreeNode pB->m_pRight->m_nValue = 2;
    Solution result;
    std::cout << result.HasSubTree(pA, pB);
}