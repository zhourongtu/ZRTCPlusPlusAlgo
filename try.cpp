#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    void quickSort(std::vector<int> nums){
        Partition(nums, 0, nums.size()-1);
    }
    int getPivot(std::vector<int> &nums, int start, int end){
        return nums[end];
    }
    void Partition(std::vector<int> &nums, int start, int end){
        if(start <= end)return;
        int i = start, j = end-1;
        int pivot = getPivot(nums, start, end);//最后一个数做枢轴量
        while(i < j){
            //i指向比pivot大
            while(nums[i] < pivot){
                i++;
            }
            //j指向比pivot小
            while(nums[j] > pivot){
                j--;
            }
            if(i<j){
                swap(nums[i], nums[j]);
            }else break;
        }
        swap(nums[i], nums[end]);
        Partition(nums, start, i-1);
        Partition(nums, i+1, end);
    }
};
int main()
{
    Solution a;
    vector<int> nums = {2,4,6,23234,32,526,1,2};
    a.quickSort(nums);
    for_each(nums.begin(), nums.end(), [](int &a){cout << a << '\t';});
    return 0;
}
