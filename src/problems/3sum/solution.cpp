class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3) return {};
        
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int beg = i+1;
            int end = nums.size()-1;
            while (beg < end) {
                int n = nums[i] + nums[beg] + nums[end];            
                if (n == 0) {
                    ans.push_back({nums[i], nums[beg], nums[end]});
                    while (beg < end && nums[beg] == nums[beg+1]) ++beg;
                    while (beg < end && nums[end] == nums[end-1]) --end;
                    ++beg, --end;
                } else if (n < 0)
                    ++beg;
                else
                    --end;
            }
        }
        
        return ans;
    }
};