class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> arr;

        for (int i = 0; i < groupSizes.size(); ++i) {
            arr[groupSizes[i]].push_back(i);
            if (arr[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(arr[groupSizes[i]]);
                arr[groupSizes[i]].clear();
            }
        }

        return ans;
    }
};