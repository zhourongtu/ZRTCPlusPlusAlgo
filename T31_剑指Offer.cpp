#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

/*最大子序列和*/
class Solution{
public:
    int FindGreatestSumOfSubArray(int *pData, int nLength){
        int max_sum = INT_MIN;
        int sum = 0;
        //解决全为负数的问题(不置0，靠上一个sum判断)
        int count = 0;
        for(int i=0; i<nLength; i++){
            if(sum <= 0){//!!妙呀
                sum = pData[i];
            }else{
                sum += pData[i];
            }
            if(sum > max_sum){
                max_sum = sum;
            }
        }
        return max_sum;
    }
};
int main()
{
    int nums[] = {-2,-3,-4,-6,-1,-32,-7,-22,-4,-314,-222};
    Solution a;
    cout << a.FindGreatestSumOfSubArray(nums, 11);
    return 0;
}
