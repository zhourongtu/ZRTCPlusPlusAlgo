#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
输入数字n，按顺序打印从1最大的n位十进制数。比如输入3-->打印1、2、3-->999
要点
1.没有给定范围，所以有可能无法用数字直接存储。
2.字符串模拟数字加法。 -->2.1 溢出判断
3.打印时不要打印0
*/
class Solution{
public:
void PrintToMaxOfNDigits(int n){
    if(n<=0)return;
    char *number = new char[n+1];
    memset(number, n, 0);
    number[n] = '\0';
    //创建一个递归调用
    for(int i=0; i<10; i++){
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    } 
}
void Print1ToMaxOfNDigitsRecursively(char *number, int n, int index){
    if(index == n-1){
        PrintNumber(number);
        return;
    }
    for(int i=0; i<10; i++){
        number[index+1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, index+1);
    }
}

void PrintNumber(char *number){
    bool isBeginning0 = true;
    int nLength = strlen(number);
    for(int i=0; i<nLength; ++i){
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if(!isBeginning0){
            cout << number[i];
        }
    }
    printf("\t");
}
};
int main()
{
    Solution a;
    a.PrintToMaxOfNDigits(2);
}