#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
找出从头到尾只出现过一次的数字
异或性质：
    A ^ B ^ B = A
*/
class Solution{
public:
    int FindAppearOnce(vector<int> &nums){
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {2,4,6,3,7,8,4,6,3,7,8};
    cout << a.FindAppearOnce(nums);
    return 0;
}
