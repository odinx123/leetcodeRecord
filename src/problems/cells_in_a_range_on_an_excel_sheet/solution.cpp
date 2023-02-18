class Solution {
public:
    vector<string> cellsInRange(string s) {
        int spPos;
        int r1 = 0, r2 = 0, c1 = 0, c2 = 0;
        vector<string> ans;

        spPos = s.find(':');
        for (int i = 0; i < spPos; ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                r1 = r1*10 + s[i] - 48;
            else
                c1 = c1*26 + s[i] - 64;
        }

        for (int i = spPos+1; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                r2 = r2*10 + s[i] - 48;
            else
                c2 = c2*26 + s[i] - 64;
        }

        for (int i = c1; i <= c2; ++i) {
            for (int j = r1; j <= r2; ++j) {
                ans.push_back(numToTitle(i)+char(j+48));
            }
        }

        return ans;
    }

    string numToTitle(int colNum) {
        string ans;
        // 除26是第26個數字進位所以要減1(0~25有26個數字)
        while (colNum-- != 0) {
            // 'A'+0 ='A' ~ 'A'+25='Z'
            char curEng = 'A' + colNum % 26;
            ans = curEng + ans;
            colNum /= 26;
        }

        return ans;
    }
};