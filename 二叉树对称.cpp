class Solution {
public:
    bool isSame(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        return root1->val == root2->val && 
        isSame(root1->left, root2->right) &&
        isSame(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSame(pRoot, pRoot);
    }

};
