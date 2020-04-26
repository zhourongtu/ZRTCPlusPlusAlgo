#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
四个数多套一层
*/
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        int len = nums.size(); 
        if(len < 4)return result;
        sort(nums.begin(), nums.end());
        int a, b, c, d;
        for(a = 0; a<len-3; a++){
            if(a>0 && nums[a]==nums[a-1])continue;
            for(b = a+1; b<len-2; b++){
                if(b>a+1 && nums[b]==nums[b-1])continue;
                c = b+1; d = len-1;
                while(c<d){
                    if(nums[a] + nums[b] + nums[c] + nums[d] < target){
                        c++;
                    }else if(nums[a] + nums[b] + nums[c] + nums[d] > target){
                        d--;
                    }else{
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        //到达相同的最后一个
                        while(c<d && nums[c+1]==nums[c])c++;//确保三个改变就行
                        while(c<d && nums[d-1]==nums[d])d--;
                        c++;
                        d--;
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
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution a;
    vector<vector<int>> result = a.fourSum(nums, target);
    usualFunc b;
    b.printTwoDimension(result);
    
}
