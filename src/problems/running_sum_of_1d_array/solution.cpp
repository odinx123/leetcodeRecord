class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> num(nums.size());
        num[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            num[i] = num[i-1] + nums[i];
        }

        return num;
    }
};