/*
重建二叉树
输入二叉树的前序和中序遍历结果，重建该二叉树。
1 2 4 7 3 5 6 8
4 7 2 1 5 3 8 6

补充:做了个类封装和友元尝试
*/
#include <iostream>
#include <vector>
using namespace std;
class BinaryTreeNode{
    int             m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
friend void in_order(BinaryTreeNode *root);
public:
    BinaryTreeNode* buildTreeByTwoSeq(vector<int> &preSeq, vector<int> &inSeq, int pre_left, int pre_right, int in_left, int in_right);
};
void in_order(BinaryTreeNode *root);
int main()
{
    int N;
    cin >> N;
    vector<int> preSeq;
    vector<int> inSeq;
    for(int i=0; i<N; i++){
        int temp; cin >> temp; preSeq.push_back(temp);}
    for(int i=0; i<N; i++){
        int temp; cin >> temp; inSeq.push_back(temp);}
    BinaryTreeNode* temp = new BinaryTreeNode;
    BinaryTreeNode* result = temp->buildTreeByTwoSeq(preSeq, inSeq, 0, N-1, 0, N-1);
    // cout << "根节点的值：" << result->m_nValue << endl;
    //N已经有了返回一个根节点
    cout << "前序遍历结果：";
    in_order(result);
    cout << endl;
}
//中序遍历
void in_order(BinaryTreeNode *root){
    if(root == NULL)return;
    cout << " " << root->m_nValue;
    in_order(root->m_pLeft);
    in_order(root->m_pRight);
    return ;
}

//依据前序与中序重建二叉树
BinaryTreeNode* BinaryTreeNode::buildTreeByTwoSeq(vector<int> &preSeq, vector<int> &inSeq, int pre_left, int pre_right, int in_left, int in_right){
    if(pre_left > pre_right){
        return NULL;
    }
    //根节点-->preSeq[pre_left]
    BinaryTreeNode *p = new BinaryTreeNode;
    p->m_nValue = preSeq[pre_left];
    //在inSeq里面找pos
    int pos;
    for(pos = in_left; pos < in_right; pos++){
        if(inSeq[pos] == p->m_nValue){
            break;
        }
    }
    //in_left~pos-1左子树-->个数为pos-in_left
    //pos+1~in_right右子树-->个数为in_right-pos
    int L_pre_left, L_pre_right, L_in_left, L_in_right;
    L_pre_left = pre_left + 1;
    L_pre_right = pre_left + (pos - in_left);
    L_in_left = in_left;
    L_in_right = pos-1; 
    int R_pre_left, R_pre_right, R_in_left, R_in_right; 
    R_pre_left = pre_left + (pos - in_left) + 1;
    R_pre_right = pre_right;
    R_in_left = pos + 1;
    R_in_right = in_right;
    p->m_pLeft = buildTreeByTwoSeq(preSeq, inSeq, L_pre_left, L_pre_right, L_in_left, L_in_right);
    p->m_pRight = buildTreeByTwoSeq(preSeq, inSeq, R_pre_left, R_pre_right, R_in_left, R_in_right);
    //pre_left+1-->左子树开头，pre_left+左子树个数+1-->右子树开头
    //pre_left+左子树个数-->左子树结尾，pre_right-->右子树结尾
    return p;
}