class Solution {
public:
    int minDistance(string word1, string word2) {
        // 先初始化insert跟delete的數量
        int wl1 = word1.size();
        int wl2 = word2.size();
        vector<vector<int>> dp(wl2+1, vector<int>(wl1+1));

        // 假設wd2的第二個字對應到wd1的第一個代表要使用這個位置等於wd2要往前移1
        // wd1要新增1個字對應wd2第一個字
        for (int i = 0; i <= wl2; ++i)
            dp[i][0] = i;
        // 假設wd2的第一個字對應到wd1的第三個字母，那要使用這個相同位置代表wd1前2個要捨去
        // 所以這個位置dp[1][3]要等於dp[0][2]
        for (int i = 0; i <= wl1; ++i)
            dp[0][i] = i;

        for (int i = 1; i <= wl2; ++i) {
            for (int j = 1; j <= wl1; ++j) {
                if (word1[j-1] == word2[i-1]) {
                    // 相同就取之前最少edit的
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // dp[i-1][j-1]+1是replace(原本最小edit加上本身不一樣)
                    // dp[i-1][j]+1是insert(wd2上個字母到這個位置繼續，wd1多一個一樣的)
                    // dp[i][j-1]+1是delete(wd2當前字母對wd1上個字母最小edit，再把wd1當前字母刪除)
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j], dp[i][j-1])+1);
                }
            }
        }

        return dp[wl2][wl1];
    }
};