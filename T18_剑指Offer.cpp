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

class Solution {
public:
    // 2是不是1的子结构
    bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        // 空树不是任意一个树的子结构-->如果2是空，则不可能是子结构，但是递归的条件下会考虑到结果。 
        if(pRoot2 == NULL || pRoot1 == NULL) return false;
        bool result = false;
        // 以该点为开始，判断是否是子结构
        if(pRoot1->m_nValue == pRoot2->m_nValue){
            result = HasSubtreeCore(pRoot1, pRoot2);
        }
        if(!result)result = HasSubTree(pRoot1->m_pLeft, pRoot2);
        if(!result)result = HasSubTree(pRoot1->m_pRight, pRoot2);
        
        return result;
    }
    
    bool HasSubtreeCore(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
        // 情况1.pRoot1为空了
        if(pRoot2 == NULL)return true;
        if(pRoot1 == NULL)return false;
        if(pRoot1->m_nValue != pRoot2->m_nValue){
            return false;
        }
        return HasSubtreeCore(pRoot1->m_pLeft, pRoot2->m_pLeft)
            && HasSubtreeCore(pRoot1->m_pRight, pRoot2->m_pRight);
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
    pB->m_pRight = new BinaryTreeNode; pB->m_pRight->m_nValue = 2;
    Solution result;
    std::cout << result.HasSubTree(pA, pB);
}