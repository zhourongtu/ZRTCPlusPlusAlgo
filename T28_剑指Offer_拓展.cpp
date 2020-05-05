#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
求k个数的组合
与DP7的递归方法联动
*/
class Solution{
public:
    void compose(string &str){
        string str_assist;
        for(int i=1; i<=str.size(); i++){
            compose_exec(str, str_assist, i, str.size()-1);
        }
    }
    void compose_exec(string &str, string &str_assist, int k, int index){
        //出口-->从后往前
        //k为还需要值的个数
        if(k == 0){
            cout << str_assist << endl; return;
        }
        if(index < k-1){
            return;//提早结束
        }
        //不取当前这个值
        compose_exec(str, str_assist, k, index-1);
        //取当前的这个值
        str_assist.push_back(str[index]);
        compose_exec(str, str_assist, k-1, index-1);
        str_assist.pop_back();
    }
};
int main()
{
    Solution a;
    string str = "zhou";
    a.compose(str);
    return 0;
}
