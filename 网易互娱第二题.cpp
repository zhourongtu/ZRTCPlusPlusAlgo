#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * VR游戏，体感....
*/
vector<vector<int>> my_map;
vector<int> my_hash_row;
vector<int> my_hash_column;
vector<int> result;
int N;
int compute_money(int x, int y){
    if(my_hash_row[x] == 1 || my_hash_column[y] == 1){
        return -1;
    }
    // 计算
    // x行
    int money = 0;
    for(int j=0; j<N; j++){
        if(my_hash_column[j] == 0){
            money += my_map[x][j];
        }
    }
    // y列
    for(int i=0; i<N; i++){
        if(my_hash_row[i] == 0){
            money += my_map[i][y];
        }
    }
    money -= my_map[x][y];
    return money;
}

void choose_to_kill()
{
    int max_money = -1;
    int temp = -1;
    int max_i, max_j;
    for(int i=0; i<N; i++){
        if(my_hash_row[i])continue;
        for(int j=0; j<N; j++){
            if(my_hash_column[j])continue;
            temp = compute_money(i, j);
            if(temp > max_money){
                max_i = i; max_j = j;
                max_money = temp;
            }
        }
    }
    // 进行一定的转换
    int count_row = 0;
    for(int i=0; i<=max_i; i++){
        if(my_hash_row[i]){
            count_row++;
        }
    }
    int count_column = 0;
    for(int j=0; j<=max_j; j++){
        if(my_hash_column[j]){
            count_column++;
        }
    }
    result.push_back(max_i - count_row);
    result.push_back(max_j - count_column);
    my_hash_row[max_i] = 1;
    my_hash_column[max_j] = 1;
    return;
}

int main()
{
    cin >> N;
    my_map.resize(N);
    for(int i=0; i<my_map.size(); i++){
        my_map[i].resize(N);
    }
    my_hash_row.resize(N);
    my_hash_column.resize(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> my_map[i][j];
        }
    }
    for(int i=0; i<N; i++){
        choose_to_kill();
    }
    for(int i=0; i<result.size(); i=i+2){
        cout << (result[i]+1) << " " << (result[i+1]+1) << endl;
    }
    return 0;
}
