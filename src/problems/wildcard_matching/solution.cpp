/*
*重點: 左邊跟上面代表著*為空或是多序列
1. 如果當前字母相等【*?也可以直接相等】，則上個p對應上個s是true，則為true。
2. "如果s上個字母對應當前p是*同時也是true，則為true，
    因為*可以多序列【s上個字母用到當前*為止是true】，*繼續"
3. "如果s當前字母對應上個p是true且當前是*，則為true，
    因為*可以為空【s當前字母用到上個p為止是true】，*為空"
4. "如果是*開頭的，那個所有相連的星星都要設為true，因為開頭的*如果要為空無法先判斷到"
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, 0));

        dp[0][0] = true;
        for (int i = 0; i < p.size() && p[i] == '*'; ++i)
            dp[0][i+1] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
                }
            }
        }

        return dp.back().back();
    }
};