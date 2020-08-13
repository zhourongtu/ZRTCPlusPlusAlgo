#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
/*
24点   
*/

class Solution {
public:
    /**
     * 
     * @param arr int整型一维数组 
     * @param arrLen int arr数组长度
     * @return bool布尔型
     */
    
    int compute_priority(char a){
        if(a == '+'){
            return 1;
        }
        if(a == '-'){
            return 1;
        }
        if(a == '*'){
            return 2;
        }
        if(a == '/'){
            return 2;
        }
        return 0;
    }
    int compute_by_op(int a, int b, char op){
        if(op == '+')return b+a;
        else if(op == '-')return b-a;
        else if(op == '*')return b*a;
        else if(op == '/')return b/a;
        return 0;
    }
    // 1.全排列 + 栈做简易计算器
    int compute(string str, int *arr, char *op){
        char temp_str[1000];
        for(int i=0; i<str.size(); i++){
            temp_str[i] = str[i];
        }
        temp_str[str.size()] = '\0';
        int result = 0;
        stack<int> data;
        stack<char> my_op;
        data.push(arr[0]);
        data.push(arr[1]);
        my_op.push(op[0]);
        if(compute_priority(op[1]) > compute_priority(my_op.top())){
            my_op.push(op[1]);
        }else{
            int a = data.top(); data.pop();
            int b = data.top(); data.pop();
            char temp_op = my_op.top(); my_op.pop();
            data.push(compute_by_op(a, b, temp_op));
            my_op.push(op[1]);
        }
        data.push(arr[2]);
        if(compute_priority(op[2]) > compute_priority(my_op.top())){
            my_op.push(op[2]);
        }else{
            int a = data.top(); data.pop();
            int b = data.top(); data.pop();
            char temp_op = my_op.top(); my_op.pop();
            data.push(compute_by_op(a, b, temp_op));
            my_op.push(op[2]);
        }
        data.push(arr[3]);
        while(!my_op.empty()){
            int a = data.top(); data.pop();
            int b = data.top(); data.pop();
            char temp_op = my_op.top(); my_op.pop();
            data.push(compute_by_op(a, b, temp_op));
        }
        if(data.top() == 24)cout << str;
        return data.top();
    }


    // 做数字的全排列
    bool DFS_number(int* arr, char* op, int deep){
        bool result = false;
        int compute_result = 0;
        if(deep == 4){
            stringstream s;
            s << arr[0];
            s << op[0];
            s << arr[1];
            s << op[1];
            s << arr[2];
            s << op[2];
            s << arr[3];
            string str;
            s >> str;
            compute_result = compute(str, arr, op);
        }else{
            for(int i=deep; i<=3; i++){
                if(false == result){
                    swap(arr[deep], arr[i]);
                    result = DFS_number(arr, op, deep+1);
                    swap(arr[deep], arr[i]);
                }
            }
        }
        if(24 == compute_result){
            result = true;
        }
        return result;
    }


    // 先做全排列(操作数)，再做简易计算器
    bool DFS(int* arr, char* op, int deep){
        bool result = false;
        int compute_result = 0;
        if(deep == 3){
            // 转字符串
            stringstream s;
            s << arr[0];
            s << op[0];
            s << arr[1];
            s << op[1];
            s << arr[2];
            s << op[2];
            s << arr[3];
            string str;
            s >> str;
            result = DFS_number(arr, op, 0);
        }else{
            op[deep] = '+';
            if(false == result)result = DFS(arr, op, deep+1);
            op[deep] = '-';
            if(false == result)result = DFS(arr, op, deep+1);
            op[deep] = '*';
            if(false == result)result = DFS(arr, op, deep+1);
            op[deep] = '/';
            if(false == result)result = DFS(arr, op, deep+1);
        }
        if(24 == compute_result){
            result = true;
        }
        return result;
    }
    
    bool Game24Points(int* arr, int arrLen) {
        int result = 0;
        for(int i=0; i<arrLen; i++){
            result += arr[i];
        }
        char op[3];
        return DFS(arr, op, 0);
    }
};
int main()
{
    Solution s;
    int arr[4];
    for(int i=0; i<4; i++){
        cin >> arr[i];
    }
    s.Game24Points(arr, 4);
    return 0;
}
