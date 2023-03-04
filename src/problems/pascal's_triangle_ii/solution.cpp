class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1, 1);
        if (rowIndex >= 1)
            ans.push_back(1);

        for (int i = 1; i < rowIndex; ++i) {
            int preN = 1;
            ans.push_back(1);
            for (int j = 1; j < ans.size()-1; ++j) {
                int temp = ans[j];
                ans[j] += preN;
                preN = temp;
            }
        }

        return ans;
    }
};