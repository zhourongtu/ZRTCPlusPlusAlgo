

// 方法1，使用两次双指针
class Solution {
public:
    bool judge(int a){
        if(a & 1){
            return true;
        }
        return false;
    }
    
    void reOrderArray(vector<int> &array) {
        int i=0, j=0;
        int count = 0;
        for_each(array.begin(), array.end(), [&count](int a){if(a & 1)count++;});
        // count 为奇数个数
        vector<int> temp_array(array);
        
        // 非原数组，偶数置前
        while(i < temp_array.size() && j < temp_array.size()){
            while(i < temp_array.size()){
                if(judge(temp_array[i])){
                    break;
                }
                i++;
            }
            j = i+1;
            if(j >= temp_array.size())break;
            while(j < temp_array.size()){
                if(!judge(temp_array[j])){
                    break;
                }
                j++;
            }
            if(i < temp_array.size() && j < temp_array.size()){
                swap(temp_array[i], temp_array[j]);
                i = i+1;
            }else {
                break;
            }
        }
        // 原数组，奇数置前
        int i=0, j=0;
        while(i < array.size() && j < array.size()){
            while(i < array.size()){
                if(!judge(array[i])){
                    break;
                }
                i++;
            }
            j = i+1;
            if(j >= array.size())break;
            while(j < array.size()){
                if(judge(array[j])){
                    break;
                }
                j++;
            }
            if(i < array.size() && j < array.size()){
                swap(array[i], array[j]);
                i = i+1;
            }else {
                break;
            }
        }
        for(int i=count; i<array.size(); i++){
            array[i] = temp_array[i-count];
        }
    }
};

// 方法2：利用插入排序
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len <= 1){ // 数组空或长度为1
            return;
        }

        int i = 0;
        while(i < len){
            int j = i + 1;
            if(array[i]%2 == 0){ // a[i]为偶数，j前进，直到替换
                while(array[j]%2 == 0){ // j为偶数，前进
                    if(j==len-1)// i为偶数，j也为偶数，一直后移到了末尾，证明后面都是偶数
                         return;
                    j++;
                }
                // 此时j为奇数
                int count = j-i;
                int temp = array[i];
                array[i] = array[j];
                while(count>1){
                    array[i+count] = array[i+count-1];//数组后移
                    count--;
                }
                array[i+1] = temp;
            }
            i++;
        }
    }
};