class Solution {
public:
    inline int removeElement(vector<int>& nums, int val) {
        return partition(nums.begin(), nums.end(), [val] (int n) {
           return n != val; 
        }) - nums.begin();
    }
};