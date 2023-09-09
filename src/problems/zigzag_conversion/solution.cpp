/*
1. sPos是2*numRow+j是因為一個col加上斜的字母分別都是numRow，
    但須要減1，因為最下面的字母有一個是共用的，自己位置再減1
2. 第一跟最後一個row不會有斜字元所以判斷掉(i != 1 && i != numRows)。
3. 每個直的字元後面接的斜的字元都根據sPos+gap取得，
    每次往下一個row，gap就會少去2，因為直跟斜字元都各少1
4. numRows==1時，2*numRows-2會等於0所以要特別判斷
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string ans;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.size(); j+=2*numRows-2) {  // j代表sPos
                ans.push_back(s[j]);

                int gap = 2 * (numRows-i-1);  // 條件3
                if (i != 0 && i != numRows-1 && j+gap < s.size()) {
                    ans.push_back(s[j+gap]);
                }
            }
        }

        return ans;
    }
};