class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (nextPermutation(nums));

        return ans;
    }
    bool nextPermutation(vector<int>& nums) {
        int left = -1, right = nums.size()-1;
        for (int i = nums.size()-1; i > 0; --i) {  // 找到第一個比右邊小的數字
            if (nums[i-1] < nums[i]) {
                left = i-1;
                break;
            }
        }

        if (left == -1) return false;

        while (nums[right] <= nums[left]) --right;  // 找到left右邊比left大的數字
        swap(nums[left], nums[right]);

        reverse(nums.begin()+left+1, nums.end());  // 交換的數字右邊都會是降序->反轉可以得到最小值
        return true;
    }
};