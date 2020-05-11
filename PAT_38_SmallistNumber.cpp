#include <algorithm> 
using namespace std; 
/*
与剑指Offer联动
特殊输入：字符串为0
01 0102
001 0010这种
*/
bool cmp0(string a, string b) {    
    return a + b < b + a; 
} 
string str[10010]; 
int main() {    
    int n;    
    scanf("%d", &n);    
    for(int i = 0; i < n; i++) cin >> str[i];    
    sort(str, str + n, cmp0);    
    string s;    
    for(int i = 0; i < n; i++) s += str[i];    
    while(s.length() != 0 && s[0] == '0') s.erase(s.begin());    
    if(s.length() == 0) cout << 0;    
    cout << s;    
    return 0; 
}