class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans.at(0).push_back(1);
        
        if (numRows > 1) {
            ans.at(1).push_back(1);
            ans.at(1).push_back(1);
        }
        
        for (int i = 2; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                cout << i << endl;
                if (j == 0 || j == i) {
                    ans.at(i).push_back(1);
                    continue;
                }
                int temp = ans.at(i-1).at(j) + ans.at(i-1).at(j-1);
                ans.at(i).push_back(temp);
            }
        }
        
        return ans;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};