class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                Swap(matrix[j][i], matrix[i][j]);
        
        for (int i = 0; i < n; ++i)
            reverse(matrix.at(i).begin(), matrix.at(i).end());
    }
    
    inline void Swap(int &a, int &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};