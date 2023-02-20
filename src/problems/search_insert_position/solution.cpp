class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;

        while (l < r) {
            mid = (r + l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // 如果只剩兩個數字mid會靠右邊的數，所以會到這代表只有左邊沒判斷
        return l;
    }
};