/*
题目：在一个二维数组中，每一行都按照从 左到右递增的顺序排序。
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入该二维数组和整数。
判断该数组中是否含有该整数。
*/
#include <iostream>
#include <vector>
using namespace std;
int find_ans(const vector<vector<int>> &arr, int result);
int main()
{
    int N, M;
    // cin >> N >> M;
    N = 4; M = 4;
    vector<vector<int> > arr;
    arr.resize(N);
    for(int i=0; i<N; i++){
        arr[i].resize(M);
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    cout << "查找5：" << find_ans(arr, 5) << endl;
    cout << "查找6：" << find_ans(arr, 6) << endl;
}
int find_ans(const vector<vector<int>> &arr, int result){
    int my_i = arr.size()-1, my_j = 0;
    int row = arr.size(), column = arr[0].size();
    while(my_i >= 0 && my_j < column){
        int now = arr[my_i][my_j];
        if(now == result){
            return 1;
        }else{
            if(now < result){
                my_i--;
            }else{
                my_j++;
            }
        }
    }
    return 0;
}
// 4 4 
// 1 2 8 9
// 2 4 9 12
// 4 7 10 13
// 6 8 11 15