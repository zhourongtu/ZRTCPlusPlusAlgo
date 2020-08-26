#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

// 其他解法
// 核心：1.暴力：查找这个点左右的最高点，该点可以存储的长度。
// 每次都要查找-->存储下来。2.遍历两次，分别存储该点左侧最高和右侧最高。
// 3.利用栈-->一次就能获取长度。
// 4.

/*请在这里输入这个程序的功能或者作用*/
class Solution {
public:
    int trap(vector<int>& height) {
        // 采用单调栈-->获取以该点为高，左右第一个比自己高的墙壁
        // 采用哈希表-->记录已经使用的墙壁
        stack<int> single_stack_down; // 单调递减的栈
        int n = height.size();
        vector<int> r_higher(n);
        vector<int> l_higher(n);
        for(int i=0; i<n; i++){
            if(single_stack_down.empty() || height[i] < height[single_stack_down.top()]){
                single_stack_down.push(i);
            }
            else{
                while(!single_stack_down.empty() && height[i] > height[single_stack_down.top()]){
                    int temp = single_stack_down.top();
                    single_stack_down.pop();
                    r_higher[temp] = i;
                }
                single_stack_down.push(i);
            } 
        }
        while(!single_stack_down.empty()){
            int temp = single_stack_down.top();
            single_stack_down.pop();
            r_higher[temp] = temp; //自己
        }

        ///////////////////////////////// 啊啊啊啊啊啊啊啊啊啊啊啊啊啊
        for(int i=n-1; i>=0; i--){
            if(single_stack_down.empty() || height[i] < height[single_stack_down.top()]){
                single_stack_down.push(i);
            }
            else{
                while(!single_stack_down.empty() && height[i] > height[single_stack_down.top()]){
                    int temp = single_stack_down.top();
                    single_stack_down.pop();
                    l_higher[temp] = i;
                }
                single_stack_down.push(i);
            } 
        }
        while(!single_stack_down.empty()){
            int temp = single_stack_down.top();
            single_stack_down.pop();
            l_higher[temp] = temp; //自己
        }
        int max_water = 0;
        for(int i=1; i<n-1; i++){
            // 开始获取左侧第一个高的值，与右侧第一个高的值
            if(height[i] == height[i-1])continue;
            int l = l_higher[i];
            int r = r_higher[i];
            if(l != i && r!=i){
                // 判定从l+1到r-1，没有一个值与height[i]相同
                int flag = 1;
                for(int j=l+1; j<i; j++){
                    if(height[j] == height[i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    max_water += (min(height[l], height[r]) - height[i]) * (r-l-1); 
                }
            }
        }
        return max_water;
    }
};

// 方法3：利用栈
/*
class Solution{
public:
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }

};
*/
int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(nums);
    return 0;
}
