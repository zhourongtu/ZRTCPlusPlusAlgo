#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
从第一个字符串中删除第二个字符串出现的所有字符
思路：hash+双指针
*/
class Solution{
public:
    void DeleteBFromA(string &A, string &B){
        int hash[256] = {0};
        for(int i=0; i<B.size(); i++){
            hash[B[i]]++;
        }
        int i=0, j=0;
        while(j < A.size()){
            if(!hash[A[j]]){
                swap(A[i], A[j]);
                i++; j++;
            }else{//出现过了不要这个字符
                j++;
            }
        }
        if(i < 1)return;
        A = A.substr(0, i);
        return;
    }

};
int main()
{
    Solution a;
    string str1 = "zhourongtu";
    string str2 = "or";
    a.DeleteBFromA(str1, str2);
    cout << str1;
    return 0;
}
