class Solution {
public:
    string convertToTitle(int colNum) {
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