class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> mp; // a+b对应次数
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) ++mp[A[i]+B[j]];
        }
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) ans += mp[0-C[i]-D[j]];
        }
        return ans;
    }
};
