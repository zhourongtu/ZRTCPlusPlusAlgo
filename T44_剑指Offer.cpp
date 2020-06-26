#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
 * 2~10为数字本身，A为1，J为11，Q为12，K为13。大王小王是任意数字
*/
class Solution{
private:
    const int _series_num = 5;
public:
    int Judge_series(vector<int> nums){
        int flag = 1;
        sort(nums.begin(), nums.end(), [](int a, int b){ return a < b;});
        int count = 0; // 允许跳过数
        int i = 0;
        while(nums[i] == 0)i++;
        count = i;
        int start = nums[i]; i++;
        for(; i<_series_num; i++){
            if(nums[i] == start){// 对子
                flag = 0; break;
            }else if(nums[i] == start+1)
            {
                ;
            }
            else if(nums[i] == start+2){
                if(count)count--;
                else{
                    flag = 0; break;
                }
            }else if(nums[i] == start+3){
                if(count == 2)count = 0;
                else{
                    flag = 0; break;
                }
            }
            start = nums[i];
        }
        return flag;
    }
};
int main()
{
    Solution s;
    vector<int> nums0 = {7, 2, 3, 4, 5};// 不可以
    vector<int> nums1 = {0, 2, 3, 4, 5};// 可以
    vector<int> nums2 = {6, 2, 3, 4, 5};// 可以
    vector<int> nums3 = {0, 0, 3, 7, 5};// 可以
    vector<int> nums4 = {0, 0, 3, 7, 6};// 可以
    cout << s.Judge_series(nums0);
    cout << s.Judge_series(nums1);
    cout << s.Judge_series(nums2);
    cout << s.Judge_series(nums3);
    cout << s.Judge_series(nums4);
    return 0;
}
