#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 寻找两个正序列数组的中位数，log(m+n)解法
 * 每次排除掉k/2的数字，利用递归完成。
*/
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len == 1){
            return nums1.size() == 0 ? nums2[0] : nums1[0];
        }
        int median;
        double result;
        if(len & 1){
            median = (len >> 1) + 1;
            result = findMedianSortedArraysCore(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, median);
        }else{
            median = (len >> 1);
            result = (findMedianSortedArraysCore(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, median)
            + findMedianSortedArraysCore(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1, median + 1))/2;
        }
        return result;
    }

    double findMedianSortedArraysCore(vector<int> &nums1, vector<int> &nums2, int start1, int end1, int start2, int end2, int k)
    {
        // 递归出口 k == 1
        if(k == 1){
            if(end1 >= start1 && end2 >= start2){
                return min(nums1[start1], nums2[start2]);
            }else if(end1 >= start1){
                return nums1[start1];
            }else return nums2[start2];
        }
        // 只剩下一个数组
        if(end1 < start1){// 剩下第二个数组
            return nums2[start2 + k - 1];
        }
        if(end2 < start2){
            return nums1[start1 + k - 1];
        }
        int compare_k1, compare_k2;
        compare_k1 = compare_k2 = k >> 1; // 比较的个数
        // 剩下两个数组，但是一个数字比compare_k小，则需要调整
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if(len1 < compare_k1){
            compare_k1 = len1;
        }
        if(len2 < compare_k2){
            compare_k2 = len2;
        }
        // 数组判断，排除掉一半的数字
        if(nums1[start1 + compare_k1 - 1] <= nums2[start2 + compare_k2 - 1]){ // nums1的数组的compare_k1个都要被排除掉
            return findMedianSortedArraysCore(nums1, nums2, start1 + compare_k1, end1, start2, end2, k - compare_k1);
        }else if(nums1[start1 + compare_k1 - 1] > nums2[start2 + compare_k2 - 1]){
            return findMedianSortedArraysCore(nums1, nums2, start1, end1, start2 + compare_k2, end2, k - compare_k2);
        }
        return 0;
    }
};
int main()
{
    vector<int> nums1 = {1, 4};
    vector<int> nums2 = {2, 3};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
