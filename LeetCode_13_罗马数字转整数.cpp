class Solution {
public:
    map<string, int> my_map = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
    int now_flag = 0;
    
public:
    int romanToInt(string s) {
        int result = 0;
        char now_index = 0;
        char now_flag[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int i;
        for(i=0; i<s.size()-1; i++){
            // 字符判断
            string with_one = s.substr(i, 1);
            string with_two = s.substr(i, 2);
            if(my_map.find(with_two) != my_map.end()){
                result += my_map[with_two];
                i++;
            }
            else if(my_map.find(with_one) != my_map.end()){
                result += my_map[with_one];
            }
        }
        if(i == s.size() - 1){
            string with_one = s.substr(i, 1);
            result += my_map[with_one];
        }
        return result;
    }
};