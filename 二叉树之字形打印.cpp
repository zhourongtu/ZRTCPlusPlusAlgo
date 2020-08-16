class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == NULL)return result;
        queue<TreeNode*> my_queue; // 层序遍历
        TreeNode* sentinal = new TreeNode(-1);
        vector<int> temp_result;
        my_queue.push(pRoot);
        my_queue.push(sentinal);
        int flag = 1; // 1为奇，2为偶
        while(!my_queue.empty()){
            TreeNode *now = my_queue.front();
            my_queue.pop();
            if(now == sentinal){
                if(flag == 1){
                    result.push_back(temp_result);
                    flag = 0;
                }else{
                    flag = 1;
                    reverse(temp_result.begin(), temp_result.end());
                    result.push_back(temp_result);
                }
                temp_result.clear();
                if(my_queue.empty()){
                    break;
                }
                my_queue.push(sentinal);
				continue;
            }
			temp_result.push_back(now->val);
            if(now->left){
                my_queue.push(now->left);
            }
            if(now->right){
                my_queue.push(now->right);
            } 
        }
        return result;
    }
};