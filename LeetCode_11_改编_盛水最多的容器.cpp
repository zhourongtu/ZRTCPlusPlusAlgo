#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        stack<int> my_stack;
        int len = height.size();
        vector<int> higher_l(len);
        vector<int> higher_r(len);
        my_stack.push(0);
        // 单调减的栈-->获取第一个高
        for(int i=1; i<len; i++){
            if(!my_stack.empty() && height[i] < height[my_stack.top()]){
                my_stack.push(i);
            }
            else{
                while(!my_stack.empty() && height[i] >= height[my_stack.top()]){
                    higher_r[my_stack.top()] = i;
                    my_stack.pop();
                }
                my_stack.push(i);
            }
        }
        while(!my_stack.empty()){
            higher_r[my_stack.top()] = my_stack.top();
            my_stack.pop();
        }
        my_stack.push(len-1);
        // 单调减的栈-->获取第一个高
        for(int i=len-2; i>=0; i--){
            if(!my_stack.empty() && height[i] < height[my_stack.top()]){
                my_stack.push(i);
            }
            else{
                while(!my_stack.empty() && height[i] >= height[my_stack.top()]){
                    higher_l[my_stack.top()] = i;
                    my_stack.pop();
                }
                my_stack.push(i);
            }
        }
        while(!my_stack.empty()){
            higher_r[my_stack.top()] = my_stack.top();
            my_stack.pop();
        }
        // 进行处理
        // 头和尾，单独处理
        int area = 0;
        for(int i=1; i<len-1; i++){
            area = max(area, min(height[higher_r[i]], height[higher_l[i]]) * (higher_r[i] - higher_l[i]));
        }
        return area;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(nums);
    return 0;
}