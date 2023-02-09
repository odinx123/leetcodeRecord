class Solution {
public:
    bool canJump(vector<int>& nums) {       
        // 每個位置可以跳得最遠距離
        int maxJump = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 如果最遠跳躍距離比當前距離小代表i之前的位置沒有可以跳到i的位置
            if (maxJump < i)
                return false;

            // 如果每次把最大跳躍距離跟可能會是最大跳躍距離比較
            maxJump = max(maxJump, nums[i] + i);
        }

        return true;
    }
};