class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size()-1;
        
        int mid = nums.size()/2;
        if (nums[beg] == target) return beg;
        if (nums.back() == target) return nums.size()-1;
        while (true) {
            if (nums[mid] == target) return mid;
            if (mid == beg) break;
            if (target < nums[mid]) {
                if (isLeftSet(nums, mid) && nums[0] > nums.back() && target < nums.front())
                    beg = mid;
                else
                    end = mid;
            } else {
                if (!isLeftSet(nums, mid) && nums[0] > nums.back() && target > nums.back())
                    end = mid;
                else
                    beg = mid;
            }
            mid = (beg+end)/2;
        }

        return -1;
    }
    
    inline bool isLeftSet(const vector<int> & nums, int pos) {
        return nums[pos] > nums.back();
    }
};