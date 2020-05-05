#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
输入一个含有n个数字的数组
对和进行对半分
思路：01背包问题
01背包问题的递归核心：
出口：1.目标为0 2.只剩下一个数字 3.只剩下当前数字过大-->一种情况。4.两种情况
*/
class Solution{
public:
void compose(vector<int> &str){
        vector<int> str_assist;
        int sum = accumulate(str.begin(), str.end(), 0);
        if(sum & 0x01)return;//奇数不行
        int target = sum >> 1;
        compose_exec(str, str_assist, str.size()-1, target);
    }
    void compose_exec(vector<int> &str, vector<int> &str_assist, int index, int target){
        //出口-->从后往前
        //k为还需要值的个数
        if(target == 0){
            for_each(str_assist.begin(), str_assist.end(), [](int &a){cout << a << '\t';});
            cout << endl;
        }else if(index == 0){
            if(str[index] == target){
                str_assist.push_back(str[index]);
                for_each(str_assist.begin(), str_assist.end(), [](int &a){cout << a << '\t';});
                cout << endl;
                str_assist.pop_back();
            }
        }else if(str[index] > target){
            //只能选择不取
            compose_exec(str, str_assist, index-1, target);
        }else{
            //不取或者取
            compose_exec(str, str_assist, index-1, target);
            str_assist.push_back(str[index]);
            compose_exec(str, str_assist, index-1, target - str[index]);
            str_assist.pop_back();
        }
        return;
    }
};
int main()
{
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution a;
    a.compose(data);
    return 0;
}
