#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include<algorithm>
using namespace std;

/*
快速排序
1.Pivot中心轴
2.大于放Pivot右边
3.小于放在Pivot左边
4.对左序列和右序列重复前三个操作
*/
class Solution{
public:
    void quickSort(std::vector<int> &nums){
        Partition(nums, 0, nums.size()-1);
    }
    //两边移动方法*************************************
    // 这里已经是quickSort了。
    void Partition(std::vector<int> &nums, int start, int end){
        if(start >= end)return;
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
        Partition(nums, start, i-1);
        Partition(nums, i+1, end);
    }

    void QuickSort(std::vector<int> &data, int start, int end){
        if(start == end)
            return;
        
        int index = Partition2(data, start, end);
        if(index > start){
            QuickSort(data, start, index-1);
        }
        if(index < end){
            QuickSort(data, index+1, end);
        }
    }
    //单边移动方法
    int Partition2(std::vector<int> &data, int start, int end){
        if(data.size() == 0 || start < 0 || end >= data.size())
            return -1;
            // throw new std::exception("Invalid Parameters");
        int index = start;//选择
        swap(data[index], data[end]);
        int small = start - 1;
        for(index = start; index < end; ++index){
            if(data[index] < data[end]){
                ++small;
                if(small != index)
                    swap(data[index], data[small]);
            }
        }
        ++small;
        swap(data[small], data[end]);
        return small;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {2,13124,2345235,56474,34,3,3,2,3,221,123,2, 3};
    // a.quickSort(nums);
    a.QuickSort(nums, 0, nums.size()-1);
    for_each(nums.begin(), nums.end(), [](int &a){cout << a << '\t';});
    return 0;
}
