class Solution {
public:
    string longestPalindrome(string s) {
        int ansLeft = 0, ansRight = 0;
        for (int i = 0; i < s.size(); ++i) {
            int left = i, right = i;

            // judge the palindromic from the mid of every substr.
            while (left >= 0 && right < s.size() && s[left]==s[right]) {
                if (right-left >= ansRight-ansLeft) {
                    ansLeft = left;
                    ansRight = right;
                    // cout << left << " " << right << endl;
                }
                --left;
                ++right;
            }

            left = i; right = i + 1;
            while (left >= 0 && right < s.size() && s[left]==s[right]) {
                if (right-left >= ansRight-ansLeft) {
                    ansLeft = left;
                    ansRight = right;
                }
                --left;
                ++right;
            }
        }
        
        // cout << ansLeft << " " << ansRight << endl;
        return std::string(s, ansLeft, ansRight-ansLeft+1);
    }
};