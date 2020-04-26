#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
两个数使用映射，三个数利用排序（因为必定N^2）
思路：与2数之和相同。得到target
排序作双指针。
有序数组双指针搜索。
*/
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        int len = nums.size(); 
        if(len < 3)return result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<len-2; i++){
            if(i==0 || (i>0 && nums[i] != nums[i-1])){//保证第一个数改变
                int p1 = i+1, p2 = len-1;
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    }else if(nums[p1] + nums[p2] == -nums[i]){
                        if(p1 == i+1 || nums[p1] != nums[p1-1]){//保证第二个数改变
                            vector<int> vtemp = {nums[i], nums[p1], nums[p2]};
                            result.push_back(vtemp);
                            vtemp.clear();
                        }
                        p1++; p2--;
                    }else{
                        p2--;
                    }
                }
            }
        }
        return result;
    }
};
class usualFunc{
public:
    void printTwoDimension(std::vector<std::vector<int>> &arr){
        using std::cout;
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                if(j!=0)cout << " ";
                cout << arr[i][j];
            }
            cout << endl;
        }
        return;
    }
};
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution a;
    vector<vector<int>> result = a.threeSum(nums);
    usualFunc b;
    b.printTwoDimension(result);
    
}
