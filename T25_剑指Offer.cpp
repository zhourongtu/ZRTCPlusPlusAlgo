#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
从根的根节点开始往下一直到叶节点所经过的结点形成一条路径。二叉树结点的定义如下。
*/
struct BinaryTreeNode{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft = NULL;
    BinaryTreeNode*     m_pRight = NULL;
};
class Solution{
private:
    vector<vector<int>> Path;
    vector<int> tempPath;
public:
    vector<vector<int>> FindPath(BinaryTreeNode* pRoot, int expectedSum){
        //用一个函数取获得以当前结点开始的结果
        travel(pRoot, expectedSum);
        vector<vector<int>> result;
        result = Path;
        Path.clear();
        return result;
    }
    //遍历结点
    void travel(BinaryTreeNode* pRoot, int expectedSum){
        if(pRoot == NULL)return;
        this->tempPath.clear();
        getPath(pRoot, 0, expectedSum);
        travel(pRoot->m_pLeft, expectedSum);
        travel(pRoot->m_pRight, expectedSum);
    }
    void getPath(BinaryTreeNode* pRoot, int nowSum, int expectedSum){
        //出口
        /*
        1.没有该结点-->这条路走不通 return
        2.有该结点-->加上该结点 > expectedSum return
        3.有该结点-->加上该结点 < expectedSum -->
            (1): == 该条路结束
            (2): <  往孩子结点继续走
                -->左
                -->右边
        */
        if(pRoot == NULL){
            return;}
        else{
            nowSum += pRoot->m_nValue;
            if(nowSum > expectedSum){
                return ;}
            else if(nowSum == expectedSum){
                tempPath.push_back(pRoot->m_nValue);
                Path.push_back(tempPath);
                tempPath.pop_back();
            }else{
                tempPath.push_back(pRoot->m_nValue);
                getPath(pRoot->m_pLeft, nowSum, expectedSum);
                getPath(pRoot->m_pRight, nowSum, expectedSum);
                tempPath.pop_back();
            
            }
        }
        return;
    }
};
int main()
{
    BinaryTreeNode *pA, *pB;
    pA = new BinaryTreeNode; pA->m_nValue = 10;
    pA->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_nValue = 5;
        pA->m_pLeft->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_pLeft->m_nValue = 4;
        pA->m_pLeft->m_pRight = new BinaryTreeNode; pA->m_pLeft->m_pRight->m_nValue = 7;
            // pA->m_pLeft->m_pRight->m_pLeft = new BinaryTreeNode; pA->m_pLeft->m_pRight->m_pLeft->m_nValue = 4;
    pA->m_pRight = new BinaryTreeNode; pA->m_pRight->m_nValue = 12;
    
    Solution a;
    vector<vector<int>> path;
    path = a.FindPath(pA, 22);
    for(int i=0; i<path.size(); i++){
        for(int j=0; j<path[i].size(); j++){
            cout << "\t" << path[i][j];
        }
        cout << endl;
    }
    return 0;
}
