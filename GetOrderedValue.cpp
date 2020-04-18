#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <sstream>
using namespace std;
//获得一个序列中正好有序的数字
int algo_(vector<int> nums);
vector<int> result;
int main()
{
    vector<int> nums = {37,25,39,41,47,45};
    algo_(nums);
    for(int i=0; i<result.size(); i++){
        if(i!=0)cout << " ";
        cout << result[i];
    }
}

int algo_(vector<int> nums){
    //思想：通过两边找当前最大和当前最小--》相等为所要
    int i=0, j=nums.size()-1;
    vector<int> now_max(nums.size());
    vector<int> now_min(nums.size());
    int max_i = 0, min_j = nums.size()-1;
    int max_num = nums[0], min_num = nums[nums.size()-1];
    for(int i=0; i<nums.size(); i++){
        if(nums[i] > max_num){
            max_num = nums[i];
        }
        now_max[i] = max_num;
        if(nums[min_j-i] < min_num){
            min_num = nums[min_j-i];
        }
        now_min[min_j-i] = min_num;
    }
    for(int i=0; i<nums.size(); i++){
        if(now_max[i] == now_min[i]){
            result.push_back(now_max[i]);
        }
    }
    return 0;
}
