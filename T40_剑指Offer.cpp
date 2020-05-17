#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
一个整型除了两个数字以外，其他数字都出现了两次，找出只出现一次的数字。
性质：自反性

分组方法：利用A ^ B. 对数字进行分组（其他都出现过两次，所以无所谓）

由于两个数字->从右边开始第一个1，一个数有，一个数没有，利用该性质，再做一次亦或
*/
class Solution{
public:
    void FindNumsAppearOnce(vector<int> &data, int *num1, int *num2){
        if(data.size() < 2)
            return;
        int resultExclusiveOR = 0;
        for(int i = 0; i < data.size(); i++){
            resultExclusiveOR ^= data[i];
        }
        //由于两个数字->从右边开始第一个1，一个数有，一个数没有，利用该性质，再做一次亦或
        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
        *num1 = *num2 = 0;
        for(int j=0; j<data.size(); ++j){
            if(IsBit1(data[j], indexOf1))//有-->num2有这个值，去掉它
                *num1 ^= data[j];
            else//没有-->num1含有这个值，去掉它
                *num2 ^= data[j];
        }
    }
    unsigned int FindFirstBitIs1(int num){
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
            num = num>>1;
            ++indexBit;
        }
        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num & 1);
    }
};
int main()
{
    int *num1 = new int;
    int *num2 = new int;
    vector<int> nums = {2, 4, 3, 6, 3, 2, 5, 5};
    Solution a;
    a.FindNumsAppearOnce(nums, num1, num2);
    cout << *num1 << " " << *num2 << endl;
    return 0;
}
