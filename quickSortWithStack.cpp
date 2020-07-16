#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

/*
 * 非递归的快速排序
*/
class Solution{
public:
    int quickSort(std::vector<int> &data, int start, int end)
    {
        // 用栈模拟
        // 原来
        stack<int> s;
        s.push(start);
        s.push(end);
        while(!s.empty())
        {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();
            int now = Partition2(data, left, right);
            if(now >= left+2)// now-1 >= left+1 保证left~now-1有两个元素
            {
                s.push(left);
                s.push(now-1);
            }
            if(now <= right-2) // now+1 <= right-1; 保证now+1~right有两个元素
            {
                s.push(now+1);
                s.push(right);
            }
        }
        return 0;
    }

    int Partition2(std::vector<int> &data, int start, int end){
        if(data.size() == 0 || start < 0 || end >= data.size())
            return -1;
            // throw new std::exception("Invalid Parameters");
        int index = start;//选择
        swap(data[index], data[end]);
        int small = start - 1;
        for(index = start; index < end; ++index){
            if(data[index] < data[end]){
                ++small;
                if(small != index)
                    swap(data[index], data[small]);
            }
        }
        ++small;
        swap(data[small], data[end]);
        return small;
    }
};
int main()
{
    Solution s;
    vector<int> data = {3, 1, 2, 6};
    s.quickSort(data, 0, data.size()-1);
    for_each(data.begin(), data.end(), [](int a){cout << a << '\t';});
    return 0;
}
