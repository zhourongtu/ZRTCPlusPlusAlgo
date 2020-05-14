#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
删除所有重复出现的字符
*/
class Solution{
public:
    void DeleteRepeat(string &str){
        int i=0, j=0;
        bool hash[256]={false};
        while(j<str.size()){
            if(!hash[str[j]]){
                swap(str[i], str[j]);
                hash[str[j]] = true;
                i++; j++;
            }else{
                j++;
            }
        }
        if(i < 1)return;
        str = str.substr(0, i);
        return;
    }
};
int main()
{
    string str = "google";
    Solution a;
    a.DeleteRepeat(str);
    cout << str;
    return 0;
}
