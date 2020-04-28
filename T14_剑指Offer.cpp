#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
输入一个整数数组，实现一个函数调整该数组中数字的顺序，使得所有奇数位于数组的前半部分
偶数位于数组的后半部分
思路：双指针移动？

//通用的一个双指针问题-->修改while循环的条件即可
*/
class Solution{
public:
void ReorderOddEven(vector<int> &data){
    int i=0, j=data.size()-1;
    //i指向偶数，j指向奇数，然后交换
    while(i < j){
        while((data[i] & 0x01) == 1){
            i++;
        }
        while((data[j] & 0x01) == 0){
            j--;
        }
        if(i < j){
            swap(data[i], data[j]);
            ++i; --j;
        }
    }
    return;
}
//通用版
void Reorder(vector<int> &data, bool(*func)(int)){
    int i=0, j=data.size()-1;
    //i指向偶数，j指向奇数，然后交换
    while(i < j){
        while(i<j && (*func)(data[i])){
            i++;
        }
        while(i<j && !(*func)(data[j])){
            j--;
        }
        if(i < j){
            swap(data[i], data[j]);
            ++i; --j;
        }
    }
    return;
}
bool isEven(int a){
    return (a & 1) == 0;
}
};
bool isEven(int a){
    return (a & 1) == 0;
}
int main()
{
    vector<int> v = {2,34,55,66,1,6};
    Solution a;
    a.Reorder(v, &isEven);
    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *it << '\t';
    }   
}