#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<int> flags(rows*cols, 0);
        for(int i=0; i<rows*cols; i++){
			flags[i] = 1;
			if(DFS(matrix, rows, cols, str, flags, i, 0)){
				return true;
			}
			flags[i] = 0;
		}
		return false;
    }
    
    bool DFS(char* matrix, const int &rows, const int &cols, char *str, vector<int> &flags, int now_pos, int now_depth)
    {
        // 当前比较的值
        if(matrix[now_pos] != str[now_depth])return false;
        if(now_depth+1 == strlen(str))return true;
        // 进行上下左右判断
        int next_pos = 0;
        int position[4];
        position[0] = -cols; // 上
        position[1] = cols; // 下
        position[2] = -1; // 左
        position[3] = 1;
        for(int i=0; i<4; i++){
            next_pos = now_pos + position[i];
            if(!(next_pos >= strlen(matrix) || next_pos < 0)){
                if(flags[next_pos] == 1)continue;
				flags[next_pos] = 1;
                if(DFS(matrix, rows, cols, str, flags, next_pos, now_depth+1)){
                    return true;
                }
                flags[next_pos] = 0;
            }
        }
        return false;
    }
};

int main()
{
	Solution s;
	cout << s.hasPath("ABCESFCSADEE",3,4,"ABCCED");
	return 0;
}