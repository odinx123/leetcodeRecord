class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = -1, r = 1;
        while (l < (int)(nums.size()-2) && r < nums.size()) {
            if (nums[++l] != 0)
                continue;
            if (r <= l) r = l + 1;
            while (r < nums.size()-1 && nums[r] == 0) ++r;

            nums[l] = nums[r];
            nums[r] = 0;
        }
    }
};