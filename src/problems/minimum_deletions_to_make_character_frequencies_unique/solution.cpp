class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cnt;
        map<int, int> record;
        int delNum = 0;

        for (int i = 0; i < s.size(); ++i)
            ++cnt[s[i]];

        for (const auto& i : cnt)
            ++record[i.second];

        int prevNum = 0;
        for (int i = record.rbegin()->first; i > 0; --i) {
            int curNum = record[i] + prevNum - 1;
            if (curNum <= 0) {
                prevNum = 0;
                continue;
            }

            delNum += curNum;
            prevNum = curNum;
        }

        return delNum;
    }
};