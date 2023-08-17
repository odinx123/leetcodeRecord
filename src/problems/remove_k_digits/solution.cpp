class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for (int i = 0; i < num.size(); ++i) {
            // 只要ans裡面有大於新的數字，就會先刪除，直到k不夠。
            // ans始終是在符k==0時的最佳解(看k足夠刪除到哪邊)。
            while (k && ans.size() && ans.back() > num[i]) {
                ans.pop_back();
                --k;
            }

            if (ans.size() + num[i]-'0')  // ans開頭不為零
                ans.push_back(num[i]);
        }
        // ans已經是最好的遞增了，所以如果k還有，那就要從後面刪除。
        while (k-- && ans.size()) ans.pop_back();

        return ans.empty() ? "0" : ans;
    }
};