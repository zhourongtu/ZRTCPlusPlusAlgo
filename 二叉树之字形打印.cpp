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

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        if (!pRoot) return ret;
        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> ans;
            while (sz--) {
                TreeNode *node = q.front();
                q.pop();
                ans.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++level;
            if (!(level&1)) // 偶数层 反转一下
                reverse(ans.begin(), ans.end());
            ret.push_back(ans);
        }
        return ret;
    }

};


int main()
{
	TreeNode *a = new TreeNode(1);
	a->left = new TreeNode(2);
	a->left->left= new TreeNode(3);
	a->right = new TreeNode(4);
	a->right->right = new TreeNode(5);
	Solution s;
	auto zhourongtu = s.Print(a);
	for(int i=0; i<zhourongtu.size(); i++){
		for(int j=0; j<zhourongtu[i].size(); j++){
			cout << zhourongtu[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}