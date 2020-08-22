class Solution {
private:
    vector<int> now_nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> now_char = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
public:
    string intToRoman(int num) {
        int now_index = 0;
        stringstream my_stream;
        while(num>0){
            // 找下标
            if(num >= now_nums[now_index]){
                num -= now_nums[now_index];
                my_stream << now_char[now_index];
            }
            else{
                now_index++;
            }
        }
        string result;
        my_stream >> result;
        return result;
    }
};

// 其他方法：硬编码
// def intToRoman(self, num: int) -> str:
//     thousands = ["", "M", "MM", "MMM"]
//     hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
//     tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
//     ones = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
//     return thousands[num // 1000] + hundreds[num % 1000 // 100] + tens[num % 100 // 10] + ones[num % 10]
