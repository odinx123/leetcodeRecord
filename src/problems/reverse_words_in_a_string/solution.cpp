class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); ++i) {
            int t = i;
            while (t < s.size() && s[t] == ' ') ++t;
            s.erase(s.begin()+i, s.begin()+t);  // [i, t)
            
            t = i+1;  // 空格刪除了i自然就在第一個字母位置
            while (t < s.size() && s[t] != ' ') ++t;  // 直到t等於空格(只有一個)

            int rev = t-1;
            while (i < rev) {  // reverse
                swap(s[i++], s[rev--]);
            }

            i = t;
        }

        if (s.back() == ' ')
            s.pop_back();

        return s;
    }
};