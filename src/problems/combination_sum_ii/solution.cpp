class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> r;
        com(candidates, target, ans, 0, r);
        
        return ans;
    } 
    
    void com(vector<int>& candidates, int target, vector<vector<int>>& ans, int pos, vector<int>& r) {
        // Base case
        if (target == 0) {
            ans.push_back(r);
            return;
        }

        // Recursion relation
        for (int i = pos; i < candidates.size() && target-candidates.at(i) >= 0; ++i) {
            if (i > pos && candidates.at(i) == candidates.at(i-1)) continue;  // 題目不要
            r.push_back(candidates.at(i));
            com(candidates, target-candidates.at(i), ans, i+1, r);
            r.pop_back();
        }
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};