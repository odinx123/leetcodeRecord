class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;  // For Answer
        
        if (nums.size() < 4) return {};
        
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); ++j) {
            if (j && nums[j] == nums[j-1]) continue; // 去重複

            for (int i = j+1; i < nums.size(); ++i) {

                int left = i+1, right = nums.size()-1;
                while (left < right) {
                    long long int n = (long long)nums[i] + nums[left] + nums[right] + nums[j];

                    if (n == target) {
                        ans.push_back({nums[j], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left, --right;
                    } else if (n < target)
                        ++left;
                    else
                        --right;
                }
                while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;  // 去重複
                // i < nums.size()-1 -> 因為i+1會超過nums的範圍
            }
        }
        
        return ans;
    }
};