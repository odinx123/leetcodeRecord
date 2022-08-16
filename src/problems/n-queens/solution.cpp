class Solution {
    int N;
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> r(N, string(N, '.'));
        vector<vector<string>> ans;
        backtracking(ans, r, 0);
        
        return ans;
    }
    
    void backtracking(vector<vector<string>>& ans, vector<string>& r, int n) {
        // Base case
        if (n == N) {
            ans.push_back(r);
            return;
        }
        
        // Recursion relation
        for (int c = 0; c < N; ++c) {
            if (isValid(n, c, r)) {
                r[n][c] = 'Q';
                backtracking(ans, r, n+1);
                r[n][c] = '.';
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
};