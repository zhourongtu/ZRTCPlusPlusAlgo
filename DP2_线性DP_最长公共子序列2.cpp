#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string a = "acdcadg";
    string b = "dcadcad";
    vector<int> dp_main(b.size()+1);
    vector<int> dp_pre(b.size()+1);
    fill(dp_pre.begin(), dp_pre.end(), 0);
    fill(dp_main.begin(), dp_main.end(), 0);
    //初始化已经完成
    int a_len = a.length(), b_len = b.length();
    a.insert(a.begin(), ' ');
    b.insert(b.begin(), ' ');
    for(int i=1; i<=a_len; i++){
        for(int j=1; j<=b_len; j++){
            if(a[i] == b[j]){
                dp_main[j] = dp_pre[j-1]+1;
            }else{
                dp_main[j] = max(dp_pre[j], dp_main[j-1]);
            }
        }
        dp_pre = dp_main;
    }
    cout << dp_main[b_len];
}