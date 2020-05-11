#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;
/*
建造一个容器，存储k个数（形成最大堆）。对所有数进行扫描一遍，如果比最大值小，则删除最大值，将数加入。
大量数据时使用非常好。只需要内存能容纳leastNumbers即可。同时也不需要修改数据。
*/
class Solution{
public:
    void GetLeastNumbers(const vector<int>& data, intSet &leastNumbers, int k){
        leastNumbers.clear();
        if(k < 1 || data.size() < k)
            return;
        
        vector<int>::const_iterator iter = data.begin();
        for(; iter!=data.end(); ++iter){
            if((leastNumbers.size() < k))
                leastNumbers.insert(*iter);
            else{
                setIterator iterGreatest = leastNumbers.begin();
                if(*iter < *(leastNumbers.begin())){
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
    }
};
int main()
{
    Solution a;
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    intSet result;
    a.GetLeastNumbers(nums, result ,4);
    for_each(result.begin(), result.end(), [](int a){ cout << a << '\t';});
    return 0;
}
