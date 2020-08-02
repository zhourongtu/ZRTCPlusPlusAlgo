class Solution {
public:
    int reverse(int x) {
        string a = to_string(x);
        if(a[0] != '-'){
            std::reverse(a.begin(), a.end());
        }else{
            std::reverse(a.begin()+1, a.end());
        }
        long long reverse_a = 0;
        int start = a[0] == '-'? 1 : 0;
        for (int i = start; i < a.length(); i++) {
            reverse_a = reverse_a*10 + (a[i]-'0');
        }
        if(start == 1)reverse_a *= -1;
        if(reverse_a > INT32_MAX || reverse_a < INT32_MIN)return 0;
        return reverse_a;
    }
};