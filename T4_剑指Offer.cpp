/*
实现一个函数，将每一个空格替换为%20
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    //直接代码法
    string a="zhourongtu shijia guo";
    // size_t temp=-3;
    // while((temp = a.find_first_of(' ', temp+3)) != string::npos){
    //     a.replace(temp, 1, "%20");
    // }

    //采用双指针
    //1.先遍历，查找空格个数
    int numBlank = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] == ' ')numBlank++;
    }
    int j = a.size() + numBlank*2 - 1;
    int i = a.size()-1;
    a.resize(j+1);//总长度
    for(; i>=0; i--){
        if(a[i] == ' '){
            a[j] = '0'; j--;
            a[j] = '2'; j--;
            a[j] = '%'; j--;
        }else{
            a[j] = a[i]; j--;
        }
    }
    cout << a;
    // cout << a;
    
}