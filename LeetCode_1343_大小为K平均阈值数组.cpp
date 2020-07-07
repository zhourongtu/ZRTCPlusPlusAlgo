class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // 检查：1. arr长度<k。 
        // 1.获得Sum数组
        // 2.ptr2， ptr1向前跑
        int len = arr.size();
        if(len < k){
            return 0;
        }
        vector<int> sum(len);
        sum[0] = arr[0];
        for(int i=1; i<len; i++){
            sum[i] = sum[i-1] + arr[i];
        }
        int count = 0;
        if(sum[k-1] / k >= threshold){
            count++;
        }
        int ptr1 = 0, ptr2 = k;
        for(; ptr2 < len; ptr1++, ptr2++){
            int k_sum = sum[ptr2] - sum[ptr1];
            if(k_sum / k >= threshold){
                count++;
            }
        }
        return count;
    }
};