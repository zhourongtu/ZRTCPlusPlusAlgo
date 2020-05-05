#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
8个数分布正方形8个顶点。
*/
class Solution{
public:
    void permutation(vector<int> &data){
        if(data.size() <= 0) return;
        int sum = accumulate(data.begin(), data.end(), 0);
        if(sum & 0x01)return;//奇数
        sum = sum >> 1;
        permutation_exec(data, 0, sum);
        return;
    }
    void permutation_exec(vector<int> &data, int index, int &target){
        if(index == data.size()-1){
            if(
                data[0] + data[1] + data[2] + data[3] == target &&
                data[0] + data[2] + data[4] + data[6] == target &&
                data[0] + data[1] + data[4] + data[5] == target
            ){
                for_each(data.begin(),data.end(), [](int &a){cout << a << '\t';});
                cout << endl;
            }
            return; 
        }
        for(int i=index; i<data.size(); i++){
            swap(data[i], data[index]);
            permutation_exec(data, index+1, target);
            swap(data[i], data[index]);
        }
    }
};
int main()
{
    Solution result;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};
    result.permutation(data);
    return 0;
}
