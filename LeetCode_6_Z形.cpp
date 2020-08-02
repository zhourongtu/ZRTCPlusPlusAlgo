#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


/*
 * 输入字符串，按Z型排列，再输出。
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> my_str(numRows);
        int now_index = 0;
        bool direction = false; //false --> ++
        // true --> --
        for(int i=0; i<s.size(); i++){//放的字符
            my_str[now_index].push_back(s[i]);
            if(now_index == numRows-1){
                direction = true;
            }else if(now_index == 0){
                direction = false;
            }
            if(direction){
                now_index--;
            }else{
                now_index++;
            }
        }
        stringstream my_stream_str;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<my_str[i].size(); j++){
                my_stream_str << my_str[i][j];
            }
        }
        string return_str;
        my_stream_str >> return_str; 
        return return_str;
    }
};

int main()
{
    Solution s;
    string temp;
    int rows;
    cin >> temp;
    cin >> rows;
    cout << s.convert(temp, rows);
    return 0;
}


