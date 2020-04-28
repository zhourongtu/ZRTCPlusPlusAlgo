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
    //没有规定n的范围？
    if(n <= 0)return;
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increment(number))//没有到最大值
    {
        PrintNumber(number);
    }
    delete []number;
}
//判断是否还能加，如果溢出，返回true
bool Increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;//前一位溢出位
    int nLength = strlen(number);
    for(int i = nLength - 1; i >= 0; i--)//最后一位开始网上+
    {
        int nSum = number[i] - '0' + nTakeOver;
        if(i == nLength - 1)//最后一位
            nSum++;
        if(nSum >= 10){
            if(i == 0)
                isOverflow = true;//结果
            else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else{
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
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