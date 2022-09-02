class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1, right = nums.size()-1;
        for (int i = nums.size()-1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                left = i-1;
                break;
            }
        }

        if (left != -1) {
            while (right > left && nums[right] <= nums[left]) --right;
            
            swap(nums[left], nums[right]);
        }

        reverse(nums.begin()+left+1, nums.end());
    }
};