#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


struct BinaryTreeNode{
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
*/
class Solution{
public:
    bool JudgeAVLTree(BinaryTreeNode *root){
        int depth = 0;
        return _JudgeAVLTree(root, depth);
    }
    bool _JudgeAVLTree(BinaryTreeNode *root, int &pDepth){
        if(root == NULL){
            pDepth = 0;
            return true;
        }
        int left_num, right_num;
        if(_JudgeAVLTree(root->m_pLeft, left_num) && _JudgeAVLTree(root->m_pRight, right_num)){
            int diff = left - right;
            if(diff <= 1 && dif >= -1){
                pDepth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};
int main()
{
    
    return 0;
}
