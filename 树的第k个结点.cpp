class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot)return NULL;
        stack<TreeNode *> res;
        TreeNode *p = pRoot;
        while(!res.empty() || p){
            while(p){
                res.push(p);
                p = p->left;
            }
            TreeNode *node = res.top();
            res.pop();
            if((--k) == 0)return node;
            p = node->right;
        }
        return NULL;
    }

    
};