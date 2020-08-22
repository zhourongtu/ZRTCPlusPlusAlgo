#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
 * 矩形面积.
 * 利用两个单调栈
*/
class Solution{
public:
    int SeeFarthest(int N, vector<int> height)
    {
        if(N == 1)return 0;
        stack<int> single_stack;
        vector<int> rectangle_higher(N);
        vector<int> rectangle_lower(N);
        // 都是单调增的栈
        // 左边到右边，第一个小于自己的值。
        single_stack.push(0);
        for(int i=1; i<N; ++i){
            // 如果更大-->入栈
            if(!single_stack.empty() && height[single_stack.top()] <= height[i]){
                single_stack.push(i);
            }else{
                // 如果栈内的都比它高-->栈内的，第一个比其矮的值，都是i
                while(!single_stack.empty() && height[single_stack.top()] > height[i]){
                    rectangle_lower[single_stack.top()] = i;
                    single_stack.pop();
                }
                single_stack.push(i);
            }
        }
        while(!single_stack.empty()){
            rectangle_lower[single_stack.top()] = N;
            single_stack.pop();
        }
        // 右边到左，第一个小于自己的值
        single_stack.push(N-1);
        for(int i=N-2; i>=0; --i){
            if(!single_stack.empty() && height[single_stack.top()] <= height[i]){
                single_stack.push(i);
            }else{
                while(!single_stack.empty() && height[single_stack.top()] > height[i]){
                    rectangle_higher[single_stack.top()] = i;
                    single_stack.pop();
                }
                single_stack.push(i);
            }
        }
        while(!single_stack.empty()){
            rectangle_higher[single_stack.top()] = -1;
            single_stack.pop();
        }
        // 开始计算面积
        int max_area = 0;
        for(int i=0; i<N; i++){
            // 从 i 开始扩展
            max_area = max(max_area, (rectangle_lower[i] - rectangle_higher[i] - 1) * height[i]);
        }
        return max_area;
    }
};
int main()
{
    Solution s;
    // int N = 5;
    // vector<int> height = {167, 168, 165, 162, 161};
    int N = 6;
    vector<int> height = {1, 1, 3, 3, 3, 1};
    
    cout << s.SeeFarthest(N, height);
    return 0;
}
