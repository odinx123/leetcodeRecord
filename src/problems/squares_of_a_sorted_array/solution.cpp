class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;

        int pos = r;
        while (pos >= 0) {
            if (nums[l]*nums[l] > nums[r]*nums[r]) {
                ans[pos--] = nums[l]*nums[l];
                ++l;
            }
            else {
                ans[pos--] = nums[r]*nums[r];
                --r;
            }
        }

        return ans;
    }
};