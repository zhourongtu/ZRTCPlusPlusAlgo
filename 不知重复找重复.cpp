class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> my_hash(length, 0);
        for(int i=0; i<length; i++){
            if(my_hash[numbers[i]] == 0){
                my_hash[numbers[i]] = 1;
            }else{
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};