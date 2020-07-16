#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
计算逆序数（逆序对的个数）
思路：利用归并排序
*/
class Solution{
public:
    int CountReverse(vector<int> &nums){
        int length = nums.size();
        int mid = (0 + nums.size()-1)/2;
        vector<int> together(nums.size());
        return MergeAndCount(nums, 0, mid, mid+1, nums.size()-1, together);
    }

    int _MergeAndCount(vector<int> &nums, int start1, int end1, int start2, int end2, vector<int> &together){
        //因为归并的左右最多差1
        int count = 0;
        auto p1 = end1; auto p2 = end2; // 一个指向最左边的最大，一个指向最右边的最大
        int p3 = (end1-start1+1) + (end2-start2+1) - 1; //归并到最后一项的位置。
        while(p3 >= 0 && p1 >= start1 && p2 >= start2){
            if(nums[p1] <= nums[p2]){ // 正常小
                together[p3] = nums[p2];
                p2--; p3--;
            }else if(nums[p1] > nums[p2]){//逆序数
                together[p3] = nums[p1];
                count += p2 - start2 + 1;
                p1--; p3--;
            }
        }
        while(p1 >= start1){
            together[p3] = nums[p1];
            p1--; p3--;
        }
        while(p2 >= start2){
            together[p3] = nums[p2];
            p2--; p3--;
        }
        int j=0;
        for(int i=start1; i<=end1; i++){
            nums[i] = together[j];
            j++;
        }
        for(int i=start2; i<=end2; i++){
            nums[i] = together[j];
            j++;
        }
        return count;
    }
    int MergeAndCount(vector<int> &nums, int start1, int end1, int start2, int end2, vector<int> &together){
        if(start1 > end1 || start2 > end2){
            return 0;
        }
        //先拆分左边
        int mid1 = (start1+end1)/2;
        int mid2 = (start2+end2)/2;
        int left = MergeAndCount(nums, start1, mid1, mid1+1, end1, together);
        int right = MergeAndCount(nums, start2, mid2, mid2+1, end2, together);
        int now = _MergeAndCount(nums, start1, end1, start2, end2, together);
        return now + right + left;
    }
    //利用类似于归并排序的性质
};
int main()
{
    Solution a;
    vector<int> nums = {10, 2, 1, 5};
    cout << a.CountReverse(nums);
    return 0;
}
