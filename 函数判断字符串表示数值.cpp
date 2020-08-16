class Solution {
public:
    bool isNumeric(char* string)
    {
        bool point  = false, exp = false;
        for(int i=0; i<strlen(string); i++){
            if(string[i] == '+' || string[i] == '-'){
                if(i+1 == strlen(string) || !(isdigit(string[i+1]) || string[i+1] == '.')){
                    return false;
                }
                if(!(i==0 || string[i-1] == 'e' || string[i-1] == 'E')){
                    return false;
                }
            }else if(string[i] == '.'){
                if(point || exp || !(i+1 < strlen(string) && isdigit(string[i+1]))){
                    return false;
                }
                point = true;
            }else if(string[i] == 'e' || string[i] == 'E'){
				if(exp || i + 1 == strlen(string) || !(isdigit(string[i+1]) || string[i+1] == '-' || string[i+1] == '+')){
					return false;
				}
				exp = true;
			}
            else if(isdigit(string[i])){
                
            }
            else{
                return false;
            }
        }
        return true;
    }

};
