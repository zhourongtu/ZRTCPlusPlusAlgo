#include <iostream>
#include <vector>
#include <map>
using namespace std;
//从一个数组中判断是否两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> my_map;
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(my_map.find(temp) != my_map.end()){
                result.push_back(my_map[temp]);
                result.push_back(i);
            }
            my_map[nums[i]] = i; 
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution a;
    vector<int> result = a.twoSum(nums, target);
}