class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 把s的每個字元往後面放，如果由同樣substring組成的s，那麼再把第一個substring
        // 放大後面之後就會發現在裡面會有s
        // 同樣s+s取1到size-1位置就會把前後substring調換，如果找的到s就是true。
        return (s+s).substr(1, 2 * (s.size()-1)).find(s) != string::npos;
    }
};