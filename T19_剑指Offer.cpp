#include <iostream>
using namespace std;
/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像
*/
struct BinaryTreeNode{
    int         m_nValue;
    BinaryTreeNode* m_pLeft = NULL;
    BinaryTreeNode* m_pRight = NULL;
};
class Solution{
public:
    void MirrorRecursively(BinaryTreeNode *pNode){
        if(pNode == NULL || (pNode->m_pLeft == NULL && pNode->m_pRight == NULL))return;
        BinaryTreeNode *temp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = temp;

        if(pNode->m_pLeft){
            MirrorRecursively(pNode->m_pLeft);
        }
        if(pNode->m_pRight){
            MirrorRecursively(pNode->m_pRight);
        }

    }
};
int main(){
    ;
}