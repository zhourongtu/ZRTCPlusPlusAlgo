#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * 寻找两个正序列数组的中位数，垃圾解法O(n/2)
*/
class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len == 1){
            return nums1.size() == 0 ? nums2[0] : nums1[0];
        }
        int median; bool flag_odd = false;
        if(len & 1){ // 奇数
            flag_odd = true;
            median = (len >> 1) + 1; // 中位数，指当前个数，奇数为median，偶数是median与前面那个。
        }else{ // 偶数
            flag_odd = false;
            median = len >> 1; // 中位数，指当前个数，奇数为median，偶数是median与前面那个。
        }

        int i = 0, j = 0;
        int count = 0;
        double now; // 当前值 或者结果
        while(i < nums1.size() && j < nums2.size()){
            if(count == median){
                if(flag_odd){
                    return now;
                }else{
                    now = (now + min(nums1[i], nums2[j])) / 2;
                    return now;
                }
            }
            if(nums1[i] < nums2[j]){
                now = nums1[i++];
            }else if(nums1[i] > nums2[j]){
                now = nums2[j++];
            }else{// 相同大小
                now = nums1[i++];
            }
            count++;
        }
        while(i < nums1.size()){
            if(count == median){
                if(flag_odd){
                    return now;
                }else{
                    now = (now + nums1[i])/2;
                    return now;
                }
            }
            now = nums1[i++];
            count++;
        }
        while(j < nums2.size()){
            if(count == median){
                if(flag_odd){
                    return now;
                }else{
                    now = (now + nums2[j])/2;
                    return now;
                }
            }
            now = nums2[j++];
            count++;
        }
        return 0;
    }
};
int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {2,3};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
