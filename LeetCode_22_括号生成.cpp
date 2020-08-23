#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str(2*n,'0');
        result.clear();
        int now_l = n, now_r = n;
        matchMore(str, 0, now_l, now_r);
        return result;
    }

    void matchMore(string &str, int now_index, int now_l, int now_r){
        if(now_l > now_r)return;
        if(now_index == str.size()){
            result.push_back(str);
            return;
        }
        if(now_l == now_r){
            str[now_index] = '(';
            matchMore(str, now_index+1, now_l-1, now_r);
        }
        if(now_l < now_r && now_l != 0){
            str[now_index] = '(';
            matchMore(str, now_index+1, now_l-1, now_r);
            str[now_index] = ')';
            matchMore(str, now_index+1, now_l, now_r-1);
        }else if(now_l < now_r){
            str[now_index] = ')';
            matchMore(str, now_index+1, now_l, now_r-1);
        }
        return;
    }

private:
    vector<string> result;
};
int main()
{
     Solution s;
     auto result = s.generateParenthesis(3);
     for_each(result.begin(), result.end(), [](string a){cout << a << "\t";});
     return 0;
}   