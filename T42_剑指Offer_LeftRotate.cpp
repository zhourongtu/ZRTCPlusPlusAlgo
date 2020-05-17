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
    void ReverseSentence(string &str, int n){
        if(n >= str.size())n = n%str.size();
        reverse(str.begin(), str.end());
        reverse(str.end()-n, str.end());
        reverse(str.begin(), str.end()-n);
        return;
    }
};
int main()
{
    Solution a;
    string str = "zhorongtu si gui a a a a";
    a.ReverseSentence(str, 3);
    cout << str;
    return 0;
}
