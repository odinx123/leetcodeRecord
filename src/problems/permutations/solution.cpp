class Solution {
    vector<vector<int>> ans;
    vector<int> r;
    bool* state;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        state = new bool[nums.size()]();
        r.resize(nums.size());
        
        backtracking(nums, 0);
        
        delete[] state;
        return ans;
    }
    
    void backtracking(vector<int>& nums, int pos) {
        // Base case
        if (pos == nums.size()) {
            ans.push_back(r);
            return;
        }
        
        // Recursion relation
        for (int i = 0; i < nums.size(); ++i) {
            if (state[i]) continue;
            state[i] = true;
            r[pos] = nums[i];
            backtracking(nums, pos+1);
            state[i] = false;
        }
    }
};