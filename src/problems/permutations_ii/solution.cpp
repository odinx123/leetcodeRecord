class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        do {
            ans.push_back(nums);
        } while (nextPermutation(nums));
        
        return ans;
    }

    bool nextPermutation(vector<int>& nums) {
        int left = -1, right = nums.size()-1;
        for (int i = nums.size()-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {  // 找到第一個升序排列的兩個數字(因為沒有等於可以去重複)
                left = i-1;
                break;
            }
        }

        if (left == -1) return false;
        
        while (right > left && nums[right] <= nums[left]) --right;
        swap(nums[left], nums[right]);

        reverse(nums.begin()+left+1, nums.end());
        return true;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};