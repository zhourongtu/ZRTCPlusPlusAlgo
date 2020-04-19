#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
/*
单调递增栈和单调递减栈
出栈的顺序为增-->递增栈
出栈的顺序为减-->递减栈

选择栈的时候，选择当前处理的值为最小-->使用递增栈
选择栈的时候，选择当前处理的值为最大-->使用递减栈
1.个子从矮到高计算可见人数-->递增栈
2.计算矩形面积从高到矮-->递减栈
3.区间元素和*区间最小值-->递增栈
*/
class Solution{
public:
int FieldSum(std::vector<int> &v)
{
    //一排人，向右看，所有人能看到的人数总和。V记录身高。
    //单调增的栈
    v.push_back(INT_MAX);
    stack<int> st;//记录栈顶元素的位置即可
    int sum=0;
    for(int i=0; i<v.size(); i++){
        if(st.empty() || v[st.top()] > v[i]){//
            st.push(i);
        }else{
            while(!st.empty() && v[st.top()] <= v[i]){
                int top = st.top();
                st.pop();
                //当前处理到第i个，top的这个人可以看到i - top - 1个人
                sum+=(i-top-1);
            }
            st.push(i);
        }
    }
    return sum;
}

int calMaxRec(vector<int> heights){
    //在单调栈中属于向左扩展，在其间解决向右扩展的问题
    //构建一个单调减栈
    //计算面积的时候是通过height[top]*可行长度
    //可行长度 = i-top;
    //那么top的值需要细细斟酌，当破坏了单调栈的时候，需要增加其长度
    //比他大的，又存储在栈中出栈的，都是允许范围
    heights.push_back(-1);//使得所有的值都能出栈
    int ret = -1;
    stack<int> st;
    for(int i=0; i<heights.size(); i++){
        if(st.empty() || heights[i]>=heights[st.top()]){
            st.push(i);
        }else{//破坏了单调性
            int temp, top;
            while(!st.empty() && heights[i] < heights[st.top()]){
                top = st.top();
                temp = heights[top];
                st.pop();
                int area = (i-top)*temp;
                if(area > ret){
                    ret = area;
                }
            }
            st.push(top);//本来是push(i)，但是这里需要增加i-top个可计算矩形长度
            heights[top] = heights[i];
        }
    }
    return ret;
}
int getSumProductSmall(vector<int> nums){
    //单调递减栈
    nums.push_back(0x7FFFFFFF);//单调递减-->MAX_INT全出栈
    stack<int> st;
    //当前和
    vector<int> vSum(nums.size()+1);
    vSum[0] = 0;
    for(int i=1; i<vSum.size(); i++){
        vSum[i] = vSum[i-1] + nums[i-1];
    }
    //vSum[i] = 前i个数的和 a->b 则v[b] - v[a]
    int top, start, end, ret = 0;
    for(int i=0; i<nums.size(); i++){
        if(st.empty() || nums[st.top()] <= nums[i]){
            st.push(i);
        }else{
            while(!st.empty() && nums[st.top()] > nums[i]){
                top = st.top();
                st.pop();
                int tmp = vSum[i] - vSum[top];
                tmp = tmp*nums[top];
                if(tmp > ret){
                    ret = tmp;
                    start = top+1;
                    end = i;
                }
            }
            st.push(top);
            nums[top] = nums[i];
        }
    }
    cout << ret << endl;
    cout << start << " " << end << endl;
    return ret;
}

};
//

int main()
{
    Solution a;
    vector<int> people = {10,3,7,4,12};
    cout << "{10,3,7,4,12}向右看最多的人数和：" << a.FieldSum(people) << endl;
    vector<int> recHeight = {2, 1, 5, 6, 2, 3};
    cout << "{2, 1, 5, 6, 2, 3}计算矩形的最大宽度：" << a.calMaxRec(recHeight) << endl;
    vector<int> seqNum = {3,1,6,4,5,2};
    a.getSumProductSmall(seqNum);
}