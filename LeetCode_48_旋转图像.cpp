class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 矩阵转置，逆序
        int n = matrix.size();
        if(n <= 1)return;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};