#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
输入一个英文句子，反转句子中单词的顺序，单词内字符顺序不变，标点符号同字母一样处理。
*/
class Solution{
public:
    void ReverseSentence(string &str){
        reverse(str.begin(), str.end());
        auto i = str.begin();
        auto j = str.begin();
        for(j=str.begin(); j!=str.end(); j++){
            if(*j == ' '){
                reverse(i, j);
                i = j+1;
            }
        }
        reverse(i, j);
        return;
    }
};
int main()
{
    Solution a;
    string str = "zhorongtu si gui a a a a";
    a.ReverseSentence(str);
    cout << str;
    return 0;
}
