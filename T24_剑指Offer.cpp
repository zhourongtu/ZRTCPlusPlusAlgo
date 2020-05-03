#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
数组：判断该数组是不是二叉搜索树的后序遍历结果
*/
class Solution{
public:
    bool VerifySequenceOfBST(std::vector<int> sequence){
        //后序遍历有什么特点？对每一个结点都是先后，再左
        return VerifySequenceOfBST_Inside(sequence, 0, sequence.size()-1);
    }
private:
    bool VerifySequenceOfBST_Inside(std::vector<int> &sequence, int start, int end){
        if(start >= end){return true;}
        int rootNum = sequence[end];
        int i;
        for(i = end-1; i>=start && sequence[i] > rootNum; i--){}
        int j = i;
        //接下来应该都小于
        for(; j>=start && sequence[j] < rootNum;j--){}
        if(j >= start)return false;//出现不符合情况的
        //i->左子树结尾  左子树start->i 右子树i->end-1
        if(i >= start){//左右子树都有
            return VerifySequenceOfBST_Inside(sequence, start, i) && VerifySequenceOfBST_Inside(sequence, i+1, end-1);
        }else{//只有右子树
            return VerifySequenceOfBST_Inside(sequence, i+1, end-1);
        }
    }
};
int main()
{
    Solution result;
    std::vector<int> nums = {5, 7, 6, 9, 11, 10, 8};
    std::vector<int> nums_No = {7, 4, 6, 5};
    cout << result.VerifySequenceOfBST(nums) << endl;
    cout << result.VerifySequenceOfBST(nums_No) << endl;
    return 0;
}
