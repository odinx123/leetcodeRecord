class Solution {
public:
    int uniquePaths(int m, int n) {
        // m+1和n+1是為了讓最開始空間有row和col一排是0
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        dp[0][1] = 1;
        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp.back().back();
    }
};