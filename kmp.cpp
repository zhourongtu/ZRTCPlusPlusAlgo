#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution{
public:
int kmp(string &fa_str, string &child_str){
    vector<int> D = kmp_D(child_str);
    int count = 0;
    int i=0, j=0;
    while(i<fa_str.size()){
        if(fa_str[i] == child_str[j]){
            i++; j++;
            if(j == child_str.size()){
                count++;
                j = 0;
                i = i-j+1;
            }
        }else{
            if(j>0){
                j = D[j-1];
            }else{
                i++;
            }
        }
    }
    return count;
}
std::vector<int> kmp_D(string &str){
    int N = str.size();
    vector<int> D(N);
    D[0] = 0;
    int len = 0; int i=1;
    while(i<N){
        if(str[len] == str[i]){
            len++;
            D[i++] = len;
        }else{
            if(len > 0){
                len = D[len-1];
            }else{
                D[i++] = 0;
            }
        }
    }
    return D;
}
};
int main()
{
    Solution a;
    string str1 = "abcdabcd", str2 = "abc";
    cout << a.kmp(str1, str2);
}