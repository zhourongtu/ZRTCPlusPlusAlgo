/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
// 这道题本质上是构建一个

class Solution {
public:
    
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		TreeLinkNode *pRoot = pNode;
		while(pRoot->next){
			pRoot = pRoot->next;
		}
        // 中序遍历，然后往右边吧
        vector<TreeLinkNode*> output;
        stack<TreeLinkNode*> my_stack;
        // 中序遍历
        my_stack.push(pRoot);
        TreeLinkNode* now = pRoot;
        while(!my_stack.empty()){
            if(now == NULL){
                now = my_stack.top();
                my_stack.pop();
                output.push_back(now);
                if(now->right){
                    my_stack.push(now->right);
                    now = now->right;
                }else{
                    now = NULL;
                }
            }
            else{ 
                while(now->left){
                    my_stack.push(now->left);
                    now = now->left;
                }
                now = NULL;
            }
        }
        for(int i=0; i<output.size()-1; i++){
            if(output[i] == pNode){
				if(i+1 != output.size()){
					return output[i+1];
				}else break;
			}
        }
		return NULL;
    }
};