class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if (num.size() == 0 || size < 1 || num.size() < size) return ret;
        int n = num.size();
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            // 维护一个单调递减的队列，下标维护
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 判断队列的头部的下标是否过期
            if (dq.front() + size <= i) {
                dq.pop_front();
            }
            // 判断是否形成了窗口
            if (i + 1 >= size) {
                ret.push_back(num[dq.front()]);
            }
        }
        return ret; 
    }
};