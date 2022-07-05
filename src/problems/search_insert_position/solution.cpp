class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        int mid;
        
        while (beg <= end) {
            mid = (beg+end)/2;
            if (nums.at(mid) == target) {
                return mid;
            } else if (nums.at(mid) > target) {
                end = --mid;
            } else {
                beg = ++mid;
            }
        }
        
        return max(beg, end);  // 若是位置小於0則是insert在0(容器都會是insert在位置前)
    }
};