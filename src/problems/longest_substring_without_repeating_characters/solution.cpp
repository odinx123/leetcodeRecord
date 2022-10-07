class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_ = 0, cur_max = 0;
        unordered_map<char, int> letters;
        
        int left = 0;
        // i is the right point of sliding windows
        for (int i = 0; i < s.size(); ++i) {
            ++letters[s[i]];
            ++cur_max;
            
            while (letters[s[i]] > 1) {
                // left++ for shrink windows
                --letters[s[left++]];
                --cur_max;
            }
            max_ = max(max_, cur_max);
        }
        
        return max_;
    }
};