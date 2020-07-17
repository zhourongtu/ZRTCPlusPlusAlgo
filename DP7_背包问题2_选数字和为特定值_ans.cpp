#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 这里只考虑次数，没考虑集合。

class Solution{
public:
int rec_subset(vector<int> arr, int i, int s);
int dp_subset(vector<int> arr, int s);
int dp_subset_opt(vector<int> arr, int s);
};
int main()
{
    Solution a;
    vector<int> arr = {3, 34, 4, 3, 5, 2};
    int S = 9;
    cout << "递归方法：" << a.rec_subset(arr, arr.size()-1, S) << endl;
    cout << "二维数组方法：" << a.dp_subset(arr, S) << endl;
    cout << "二维数组优化方法：" << a.dp_subset_opt(arr, S) << endl;
}
int Solution::rec_subset(vector<int> arr, int i, int s)
{
    if(s==0){
        return 1;
    }else if(i==0){
        return s == arr[0];
    }else if(s < arr[i]){
        return rec_subset(arr, i-1, s);
    }else{
        return rec_subset(arr, i-1, s) + rec_subset(arr, i-1, s-arr[i]);
    }
}
int Solution::dp_subset(vector<int> arr, int s)
{
    int num_column, num_row;
    num_column = s+1; 
    num_row = arr.size();
    int subset[num_row][num_column]={0};
    fill(subset[0], subset[0]+num_column*num_row, 0);
    subset[0][0] = 0;//从1开始，因为如果没有数组则一定为0
    for(int i=1; i<num_row; i++){
        subset[i][0] = 1;
    }
    for(int j=0; j<num_column; j++){
        if(j == arr[0]){
            subset[0][j] = 1;
        }
    }
    //循环
    for(int i=1; i<num_row; i++){
        for(int j=1; j<num_column; j++){
            if(j < arr[i]){
                subset[i][j] = subset[i-1][j];
            }else{
                subset[i][j] = subset[i-1][j-arr[i]] + subset[i-1][j];
            }
        }
    }
    return subset[num_row - 1][num_column - 1];
}
int Solution::dp_subset_opt(vector<int> arr, int s)
{
    //需要两行
    int num_column = s+1, num_row = arr.size();
    int last_row[num_column] = {0};
    int current_row[num_column] = {0};
    //第一行
    for(int j=0; j<num_column; j++){
        if(j == arr[0]){
            last_row[j] = 1;
        }
    }
    //循环num_row-1次
    int now_at = 1;//分析这一行的情况
    int i=1;
    for(int k=0; k<num_row-1; k++){//k表示次数
        //第0列为1
        current_row[0] = 1;
        for(int j=1; j<num_column; j++){
            if(j<arr[i]){
                current_row[j] = last_row[j];
            }else{
                current_row[j] = last_row[j] + last_row[j-arr[i]];
            }
        }
        memcpy(last_row, current_row, num_column*sizeof(int));
        i++;
    }
    
    return last_row[num_column-1];
}
