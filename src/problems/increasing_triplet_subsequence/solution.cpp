class Solution {
public:
    // 一定要有比Left大的Mid出現，才有可能是true;
    bool increasingTriplet(vector<int>& nums) {
        // mid的value被設定代表曾經出現比mid小的left
        // 所以有大於mid的值就會return true;
        int Left = INT_MAX, Mid = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > Mid)
                return true;
            else if (nums[i] > Left && nums[i] < Mid)  // 找更小的Mid
                Mid = nums[i];  // 比左大又比原本Mid小->更好的選擇
            else if (nums[i] < Left)
                Left = nums[i];  // 新的位置有可能成為新的左值(Mid已經被設定過了，要找更小的Mid)
        }
        
        return false;
    }
};