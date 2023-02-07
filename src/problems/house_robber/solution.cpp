class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int curr = nums[0], prev1 = nums[1], prev2 = nums[0];

        // 想法:對當前位置來說只有前一個位置不能加上數字
        // 而前一個位置是之前所有最大的數字
        for (int i = 2; i < nums.size(); ++i) {
            // 前前一個加上當前數字跟前一個比較
            // 而prev2跟prev1會一直更新(DP)成比較好的數字
            curr = max(nums[i] + prev2, prev1);
            
            // 因為只要空超過一格的位置都可以，所以選擇較大的留下
            prev2 = max(prev1, prev2);

            // 更新當前最大數字
            prev1 = curr;
        }

        return curr;
    }
};