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
二叉树的深度
*/
class Solution{
public:
    int DepthOfTree(BinaryTreeNode* root){
        if(root == NULL)return 0;
        return max(DepthOfTree(root->m_pLeft), DepthOfTree(root->m_pRight)) + 1; 
    }
};
int main()
{
    
    return 0;
}
