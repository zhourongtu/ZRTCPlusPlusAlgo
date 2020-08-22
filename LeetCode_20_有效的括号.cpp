class Solution {

public:
    bool isValid(string s) {
        if(s == "")return true;
        stack<char> my_stack;
        map<char, char> my_map;
        my_map['}'] = '{';
        my_map[']'] = '[';
        my_map[')'] = '(';
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                my_stack.push(s[i]);
            }
            else{
                if(my_stack.empty() || my_stack.top() != my_map[s[i]]){
                    return false;
                }else{
                    my_stack.pop();
                }
            }
        }
        if(!my_stack.empty())return false;
        return true;
    }
};