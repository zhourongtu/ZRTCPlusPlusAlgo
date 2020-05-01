#include <iostream>
#include <vector>
using namespace std;
/*
打印矩阵的一圈
*/
class Solution{
public:
    void PrintMatrixClockwisely(vector<vector<int>> numbers){
        if(numbers.empty())return;
        if(numbers[0].empty())return;
        //打一个包围圈-->起点_x, _x。长度
        int i=0;
        int rows = numbers.size();
        int columns = numbers[0].size();
        while(rows > 0 && columns > 0 ){
            printCircle(numbers, i, rows, columns);
            i++;
        }
    }
    void printCircle(vector<vector<int>> nums, int start, int &rows, int &columns){
        //1.向右到头
        for(int j = start; j < start + columns; j++){//这里用i代替列
            cout << nums[start][j] << "\t";
        }
        //2.从上到下
        int j = start + columns - 1;;
        for(int i = start+1; i < start + rows; i++){
            cout << nums[i][j] << "\t";
        }
        //3.从右到左边
        int i = start + rows - 1;
        j = start + columns - 2;
        for(j = start + columns - 2; j >= start; j--){
            cout << nums[i][j] << "\t";
        }
        //4.从左边到上面
        j = start;
        for(i = start + rows - 2; i > start; i--){
            cout << nums[i][j] << "\t";
        }
        rows -= 2;
        columns -= 2;
    }
};
int main()
{
    vector<vector<int> > nums;
    nums.resize(4);
    int number = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            nums[i].push_back(number);
            ++number;
        }
    }
    Solution result;
    result.PrintMatrixClockwisely(nums);


}