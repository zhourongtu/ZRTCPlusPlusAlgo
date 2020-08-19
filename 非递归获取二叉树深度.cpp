/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {// 采用非递归的一种解法，通过层序遍历，用size判断当前层结束
        if(pRoot == NULL)return 0;
        queue<TreeNode*> my_queue;
        int level = 0;
        int my_size = 1;
        my_queue.push(pRoot);
        while(!my_queue.empty()){
            while(my_size){
                auto temp = my_queue.front();
                my_queue.pop();
                if(temp->left){
                    my_queue.push(temp->left);
                }
                if(temp->right){
                    my_queue.push(temp->right);
                }
                my_size--;
            }
            my_size = my_queue.size();
            level++;
        }
        return level;
    }
    
    
};