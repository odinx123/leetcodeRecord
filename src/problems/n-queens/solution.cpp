class Solution {
    int N;
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> r(N, string(N, '.'));
        vector<vector<string>> ans;
        backtracking(ans, r, 0, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<string>>& ans, vector<string>& r, int n, int pos) {
        // Base case
        if (n == N) {
            ans.push_back(r);
            return;
        }
        
        // Recursion relation
        for (int i = pos/N; i < N; ++i) {
            int j = i == pos/N ? pos%N : 0;
            for (; j < N; ++j) {
                if (!isValid(i, j, r)) continue;
                
                r[i][j] = 'Q';
                backtracking(ans, r, n+1, i*N+j+1);
                r[i][j] = '.';
            }
        }
    }
    
    bool isValid(int i, int j, const vector<string>& r) {
        for (int pos = 1; pos < N; ++pos) {
            if (i + pos < N && r[i+pos][j] == 'Q')
                return false;
            if (i - pos >= 0 && r[i-pos][j] == 'Q')
                return false;
            if (j + pos < N && r[i][j+pos] == 'Q')
                return false;
            if (j - pos >= 0 && r[i][j-pos] == 'Q')
                return false;
            if (i + pos < N && j + pos < N && r[i+pos][j+pos] == 'Q')
                return false;
            if (i - pos >= 0 && j - pos >= 0 && r[i-pos][j-pos] == 'Q')
                return false;
            if (i + pos < N && j - pos >= 0 && r[i+pos][j-pos] == 'Q')
                return false;
            if (i - pos >= 0 && j + pos < N && r[i-pos][j+pos] == 'Q')
                return false;
        }
        return true;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};