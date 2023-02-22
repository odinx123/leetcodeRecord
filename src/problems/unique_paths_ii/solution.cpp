class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0 && grid[i-1][j] != 1)
                    dp[i][j] += dp[i-1][j];
                if (j > 0 && grid[i][j-1] != 1)
                    dp[i][j] += dp[i][j-1];
            }
        }

        // 如果終點本身是障礙物就是沒有可能到終點
        return grid.back().back() != 1 ? dp.back().back() : 0;
    }
};