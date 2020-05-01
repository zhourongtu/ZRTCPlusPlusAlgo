#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

/*
从上到下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
思路：层序遍历
*/
struct BinaryTreeNode{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
        if(pTreeRoot == NULL)return;
        queue<BinaryTreeNode*> q;
        q.push(pTreeRoot);
        while(!q.empty()){
            BinaryTreeNode *temp = q.front();
            q.pop();
            using std::cout;
            cout << temp->m_nValue << '\t';
            if(temp->m_pLeft){
                q.push(temp->m_pLeft);}
            if(temp->m_pRight){
                q.push(temp->m_pRight);}
        }
        return; 
    }
};
int main()
{
    
    return 0;
}
