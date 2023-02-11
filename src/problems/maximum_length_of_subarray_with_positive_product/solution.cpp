class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negNum = 0, maxLen = 0, negLen = 0, lengthSoFar = 0;
        int minNegPos = nums.size()-1;

        // 每個0可以當作一個分段點分開計算
        // 如果某個分段中有奇數是個負數，那就比較之前計算的跟【第一個負數】後長度
        // 如果是正數，那就直接計算當前分段中的全部
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                minNegPos = nums.size()-1;
                negLen = lengthSoFar = negNum = 0;
            } else {
                // negNum已經包含當前位置的數字了
                if (nums[i] < 0) {
                    ++negNum;
                    minNegPos = min(minNegPos, i);
                }

                if (i > minNegPos) {
                    ++negLen;
                }
                ++lengthSoFar;

                if (negNum & 1) {
                    maxLen = max(maxLen, negLen);
                } else
                    maxLen = max(maxLen, lengthSoFar);
            }
        }

        return maxLen;
    }
};