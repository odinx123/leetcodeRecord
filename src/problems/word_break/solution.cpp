class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word_set(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.size()+1,0);
        dp[0]=1;

        // 每個字串都要把全部的字都配對到
        // 但是dict不一定都要用到，所以有可能出現使用錯誤dict的字串
        // 所以dp來把每個單字的最尾端都記住，如果可以就是true
        // 代表迴圈掃過所有組合

        // 如果掃過某自i的位置到最後都是false代表前面某次找不到
        // 也代表沒有dict的組合return false
        for (int i = 0; i < s.size(); ++i){
            if (!dp[i]) continue;
            for (int j = i+1; j <= s.size(); ++j){
                if (word_set.count(s.substr(i,j-i)))
                    dp[j]=1;
            }
        }

        return dp[s.size()];
    }
};