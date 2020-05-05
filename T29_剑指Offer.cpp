#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。其中2出现5次超过一半。
1.排序，顺序搜索。
2.基于快速排序的partition
*/
class Solution{
public:
    int MoreThanHalfNum(std::vector<int> &nums){
        int length = nums.size();
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        int index = Partition(nums, start, end);
        while(index != middle){
            if(index > middle){
                end = index - 1;
                index = Partition(nums, start, end);
            }
            else{
                start = index + 1;
                index = Partition(nums, start, end);
            }
        }
        int result = nums[middle];
        return result;
    }
    int Partition(std::vector<int> &nums, int start, int end){
        if(start >= end)return start;
        int i = start, j = end;
        int temp = nums[start];
        //保证每一次有一个空位，最后产生一个空位
        while(i < j){
            //指向小的
            for(; i<j && nums[j] >= temp; j--);
            if(i<j){
                nums[i++] = nums[j];
            }
            //指向大的
            for(; i<j && nums[i] <= temp; i++);{
                nums[j--] = nums[i];
            }
        }
        nums[i] = temp;
        return i;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution a;
    cout << a.MoreThanHalfNum(nums);
    return 0;
}
