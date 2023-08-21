/*
1. 如果遇到*，先檢查前一個p是否為.或相同字母
2. 如果是相同，那就檢查上面，也就是s上個字母在*是否為true，如果是，代表*可以繼續延長
3. 檢查左邊，代表上個p對當前s，如果為true，那麼就代表*可以為true，因為*可以為空
4. 如果是*還要判斷左邊的左邊是不是true
#備註: 檢查左上，代表上個s對上個p，所以上個p跟當前s一樣且左上為true的話上面也會是true
#重要: a*可以代表一個a和空或是全空 EX: a*a對上a為true
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1));

        dp[0][0] = true;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == '*') dp[0][i+1] = true;
            else if (p[i-1] != '*') break;
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                // 如果是*就比對前一個p跟當前s是否相同。
                else if (p[j-1] == '*') {
                    // j-2是要如果*跟p前一個都空是否為true
                    dp[i][j] = dp[i][j-2] || 
                    (p[j-2] == s[i-1] || p[j-2] == '.') && (dp[i-1][j] || dp[i][j-1]);
                    // 兩段的比較->前半段是因為*可以連帶前面都為空，後面則是有最開始的解釋。
                }
            }
        }

        return dp.back().back();
    }
};