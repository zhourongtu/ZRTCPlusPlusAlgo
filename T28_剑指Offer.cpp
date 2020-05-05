#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

/*
字符串的全排列
*/
class Solution{
public:
    void permutation(string &str){
        if(str.size() <= 0) return;
        permutation_exec(str, 0);
        return;
    }
    void permutation_exec(string &str, int index){
        if(index == str.size()-1){
            print_str(str);
            return; 
        }
        for(int i=index; i<str.size(); i++){
            swap(str[i], str[index]);
            permutation_exec(str, index+1);
            swap(str[i], str[index]);
        }
    }
    void print_str(string &str){
        cout << str << endl;
        return;
    }
};
int main()
{
    Solution result;
    string str = "abc";
    result.permutation(str);
    return 0;
}
