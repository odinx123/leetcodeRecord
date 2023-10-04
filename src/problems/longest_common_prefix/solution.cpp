class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;

        bool state = true;
        for (int j = 0; state && j < strs[0].size(); ++j) {
            int cur = strs[0][j];
            for (int i = 1; i < strs.size() && j < strs[0].size(); ++i) {
                if (cur != strs[i][j]) {
                    state = false;
                    break;
                }
            }

            if (state) s.push_back(cur);
        }

        return s;
    }
};