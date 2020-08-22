#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

/*请在这里输入这个程序的功能或者作用*/
class Solution{
public:
    bool isMatch(string s, string p){
        int len_s = s.size();
        int len_p = p.size();
        vector<vector<int>> f(len_s+1, vector<int>(len_p+1, 0));
        auto temp_judge = [&](int i, int j){ // 匹配坐标第i-1个和第j-1个
            if(i==0)return false;//相当于
            if(p[j-1] == '.')return true;
            return s[i-1] == p[j-1];
        };
        f[0][0] = true;
        for(int i=0; i<=len_s; i++){
            for(int j=1; j<=len_p; j++){
                if(p[j-1] == '*'){
                    f[i][j] = f[i][j-2];
                    if(temp_judge(i, j-1)){
                        f[i][j] |= f[i-1][j];
                    }
                }
                else{
                    if(temp_judge(i, j)){
                        f[i][j] |= f[i-1][j-1];
                    }
                }
            }
        }
        return f[len_s][len_p];
    }
};
int main()
{

    return 0;
}
