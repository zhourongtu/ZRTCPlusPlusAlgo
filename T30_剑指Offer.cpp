#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
输入n个整数，找出其中最小的k个数。
*/
class Solution{
public:
    void GetLeastNumbers(std::vector<int> &nums, int k){
        int start = 0;
        int end = nums.size()-1;
        int index = Partition(nums, start, end);
        while(index != k-1){
            if(index > k-1){
                end = index - 1;
                index = Partition(nums, start, end);
            }
            else{
                start = index + 1;
                index = Partition(nums, start, end);
            }
        }
        for_each(nums.begin(), nums.begin()+k, [](int &a){cout << a << '\t';});
        cout << endl;
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
    Solution a;
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    a.GetLeastNumbers(nums, 4);
    return 0;
}
