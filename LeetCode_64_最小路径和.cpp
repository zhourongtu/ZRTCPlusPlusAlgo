#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(i==0 && j==0){
                    continue;
                }else if(i==0){
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }else if(j==0){
                    grid[i][j] = grid[i-1][j] +  grid[i][j];
                }else{
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                }
            }
        }
        return grid[rows-1][columns-1];
    }
};

int main()
{
    vector<vector<int>> nums(2, vector<int>(2, 0));
    nums[0][0] = 1;
    nums[0][1] = 2;
    nums[1][0] = 1;
    nums[1][1] = 1;
    Solution s;
    cout << s.minPathSum(nums);
    return 0;
}
