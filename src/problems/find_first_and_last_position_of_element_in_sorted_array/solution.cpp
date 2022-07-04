class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid = (start+end)/2;
        
        int pos1 = -1, pos2 = -1;
        while (start <= end) {
            if (nums.at(mid) == target) {
                pos1 = mid;
                end = --mid;
            } else if (nums.at(mid) >= target) {
                end = --mid;
            } else {
                start = ++mid;
            }
            mid = (start+end)/2;
        }
        start = 0, end = nums.size()-1;
        while (start <= end) {
            if (nums.at(mid) == target) {
                pos2 = mid;
                start = ++mid;
            } else if (nums.at(mid) <= target) {
                start = ++mid;
            } else {
                end = --mid;
            }
            mid = (start+end)/2;
        }
        
        return {pos1, pos2};
    }
};