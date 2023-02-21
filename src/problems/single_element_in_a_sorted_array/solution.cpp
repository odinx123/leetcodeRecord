class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid;
        
        // 想法:只有一個是單個數字所以一定是奇數個數字
        // 判斷相同是左邊還是右邊來移動mid
        // 如果相同是左邊代表右邊都是偶數不會有奇數反之一樣(左右邊奇數偶數不一樣)
        while (l <= r) {
            mid = l + (r - l) / 2;

            if (!((mid-l)&1)) {
                if (mid > 0 && nums[mid] == nums[mid-1]) {
                    r = mid - 2;  // -2是為了跳過相同的
                } else if (mid < nums.size()-1 && nums[mid] == nums[mid+1]) {
                    l = mid + 2;
                } else
                    return nums[mid];
            } else {  // 奇數相同往反邊
                if (mid > 0 && nums[mid] == nums[mid-1]) {
                    l = mid + 1;  // 只-1是因為相同的在另一邊
                } else if (mid < nums.size()-1 && nums[mid] == nums[mid+1]) {
                    r = mid - 1;
                } else
                    return nums[mid];
            }
        }

        return r;
    }
};