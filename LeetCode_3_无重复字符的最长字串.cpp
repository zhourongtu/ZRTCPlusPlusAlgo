#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度
*/
class Solution{
public:
    int lengthOfLongestSubstring(string &str){
        int max_index = 0, max_length = 0;
        int now_length = 0;
        int start = 0;
        int hash[256] = {0};
        for(int i=0; i<str.size(); i++){
            if(hash[str[i]] == 0 || i == str.size()-1){//最后一个字符了
                if(hash[str[i]] == 0){
                    hash[str[i]] = 1;
                    now_length = i-start + 1;
                }
                if(now_length > max_length){
                    max_length = now_length;
                }
            }else{//已经存在该字符了
                while(str[start] != str[i]){
                    hash[str[start]]=0;
                    start++;
                }//此时start指向与str[i]相同的字符
                if(start != i){
                    start++;
                }
            }
        }
        return max_length;
    }
};
int hash[256];
int main()
{
    string str = "pwwkew";
    Solution a;
    char s[] = "sss";
    cout << a.lengthOfLongestSubstring(str);
}