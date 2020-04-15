#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution{
public:
int choose_maxSum(std::vector<int> &nums){
    using std::vector;
    int N = nums.size();
    if(N == 1){
        return nums[0];
    }
    // vector<int> opt(N);
    // opt[0] = nums[0]; opt[1] = max(nums[0], nums[1]);
    // for(int i=2; i<N; i++){
    //     opt[i] = max(opt[i-1], opt[i-2]+nums[i]);
    // }
    // return opt[N-1];
    
    //状态压缩
    int opt1, opt2, opt3;
    opt1 = nums[0];
    opt2 = max(nums[0], nums[1]);
    for(int i=2; i<N; i++){
        opt3 = max(opt2, opt1 + nums[i]);
        opt1 = opt2;
        opt2 = opt3;
    }
    return opt2;
}
};
int main()
{
    Solution a;
    vector<int> nums = {1, 2, 4, 1, 7, 8, 3};
    cout << a.choose_maxSum(nums);
}