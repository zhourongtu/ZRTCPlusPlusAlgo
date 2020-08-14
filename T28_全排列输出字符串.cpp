#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() == 0)return vector<string>();
        sort(str.begin(), str.end());
        vector<string> result;
        Permutation(str, 0, result);
        map<string, int> my_map;
        for(int i=0; i<result.size(); i++){
            my_map[result[i]] = 0;
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    void Permutation(string &str, int deep, vector<string> &result){
        if(deep == str.size()){
            result.push_back(str);
//            cout << str << endl;
        }else{
            for(int i=deep; i<str.size(); i++){
                swap(str[i], str[deep]);
                Permutation(str, deep + 1, result);
                swap(str[i], str[deep]);
            }
        }
    }
};

