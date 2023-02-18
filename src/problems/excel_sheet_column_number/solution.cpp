class Solution {
public:
    int titleToNumber(string s) {
        long long int cnt = 0;
        for (int i = 0; i < s.size(); ++i)
            cnt = cnt*26 + s[i] - 64;

        return cnt;
    }
};