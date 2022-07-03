class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int num = 2;  // 初始點跟結束點都算一個

        for (int i = 1; i < nums.size()-1; ++i) {
            int j = i;
            while (nums[i] == nums[i+1] && i+1 < nums.size()) ++i;
            //去重複

            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                ++num;
            else if (nums[i] < nums[i-1] && nums[i] < nums[i+1])
                ++num;
            else if (j && nums[j-1] < nums[j] && nums[i+1] < nums[i])
                ++num;
            else if (j && nums[j-1] > nums[j] && nums[i+1] > nums[i])
                ++num;
        }
        
        int size = num == 2 && nums.front() == nums.back() ? 1 : nums.size();
        return min(size, num);
    }
};
// 找到所有的峰值
// 找峰值可以把遞增的數字或遞減的刪除(相當於嚴格擺動子序列)
// 若是有多個相同的值->紀錄第一個相同值位置j，把i遞增到最後一個相同值進行判斷