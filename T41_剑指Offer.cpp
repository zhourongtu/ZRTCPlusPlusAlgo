#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
一排递增数组，一个数字s，查找两个数使得其和正好是s

与LeetCode第一题相似：Two Sum
但是有序：可利用双指针
*/
class Solution{
public:
    vector<int> FindTwoAddToTarget(vector<int> &nums, int target){
        vector<int> result;
        if(nums.size() < 2)return result;
        int i=0, j=nums.size()-1;
        while(i<j && nums[i] + nums[j] != target){
            if(nums[i] + nums[j] < target){
                i++;
            }else{
                j--;
            }
        }
        if(i < j){
            result.push_back(i);
            result.push_back(j);
        }
        return result;
    }
    // vector<int> FindTwoAddToTarget(vector<int> &nums, int target){
    //     vector<int> result;
    //     map<int, int> my_map;
    //     for(int i=0; i<nums.size(); i++){
    //         int temp = target - nums[i];
    //         if(my_map.find(temp) != my_map.end()){
    //             result.push_back(my_map[nums[i]]);
    //             result.push_back(i);
    //         }
    //         my_map[nums[i]] = i;
    //     }
    //     return result;
    // }
};
int main()
{
    
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution a;
    vector<int> result = a.FindTwoAddToTarget(nums, target);
    for_each(result.begin(), result.end(), [](int a){cout << a << '\t';});
    return 0;
}
