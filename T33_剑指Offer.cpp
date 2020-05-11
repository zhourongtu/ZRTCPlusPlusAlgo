#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
把数组排成最小的数
与PAT_38联动
（那种相对高级，考虑字符串中0的问题)

比较规则有效的三个性质：自反性，对称性，传递性。
*/
class Solution{
public:
    string SortArrayToSmallist(vector<int> &nums){
        vector<string> nums_str;
        for(auto i:nums){
            nums_str.push_back(to_string(i));
        }
        sort(nums_str.begin(), nums_str.end(), [](string a, string b){return (a+b) < (b+a)?1:0;});
        string result;
        for(auto i:nums_str){
            result = result+(i);
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {3, 32, 321};
    Solution a;
    cout << a.SortArrayToSmallist(nums);
    return 0;
}
