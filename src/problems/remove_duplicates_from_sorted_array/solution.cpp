class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, pos = 0;
        if (nums.size() == 1) return 1;
        while (++pos < nums.size()) {
            if (nums[k] != nums[pos])
                nums[++k] = nums[pos];
        }
        return ++k;
    }
};