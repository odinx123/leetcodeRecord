class Solution {
public:
    // 任意兩邊和大於第三邊
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int max_ = 0;
        
        int size = nums.size() - 2;
        for (int i = 0; i < size; ++i) {
            if (nums[i] < nums[i+1] + nums[i+2])
                max_ = max(max_, nums[i]+nums[i+1]+nums[i+2]);
        }
        
        return max_;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};