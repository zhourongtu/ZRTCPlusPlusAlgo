#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
第一个只出现一次的字符
*/
class Solution{
public:
    char FirstNotRepeatingChar(string &str){
        int hash[256] = {0};
        for(int i=0; i<str.size(); i++){
            hash[str[i]]++;
        }
        int i;
        for(i=0; i<str.size(); i++){
            if(hash[str[i]] == 1)break;
        }
        return str[i];
    }
};
int main()
{
    string a = "zhourongtu";
    Solution solve;
    cout << solve.FirstNotRepeatingChar(a);
    return 0;
}
