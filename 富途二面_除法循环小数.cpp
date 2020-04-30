#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//字符串除法循环小数问题
class Solution{
public: 
    void convert(int a, int b){
        int integer = a/b;
        a = a%b;
        if(a == 0){
            cout << integer;
            return;
        }
        cout << integer << ".";
        int i=0;
        string temp;
        map<int, int> modNum; int hash[10] = {0};
        //余数出现相同则会出现循环
        int flag = 0;
        int start = 0;
        while(true){
            a = a*10;
            char c = a/b + '0';
            a = a%b;
            if(a == 0){
                temp.push_back(c);//除干净了
                break;
            }
            //开始查找
            if(modNum.find(a) == modNum.end()){
                //说明不存在这个指
                hash[c-'0'] = 1;
                modNum[a] = i;//加入
            }else{
                //出现相同余数且数字出现过，说明已经不行了
                if(hash[c-'0'] != 0){
                    start = modNum[a];//最后一个起点
                    flag = 1;
                    break;
                }else{
                    hash[c-'0'] = 1;
                    modNum[a] = i;
                }
            }
            temp.push_back(c);
            i++;
        }//简单来个一百位吧
        if(start!=0)cout << string(temp.begin(), temp.begin()+start);
        if(flag)cout << "(";
        cout << string(temp.begin()+start, temp.end());
        if(flag)cout << ")" << endl;
    }
};
int main()
{
    // int a = 1, b = 7;
    int a, b;
    cin >> a >> b;
    Solution result;
    result.convert(a, b);
}
