class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = nums1.size()-1; i >= 0; --i) {
            if (n > 0 && m > 0) {
                nums1.at(i) = nums1.at(m-1) > nums2.at(n-1) ? nums1.at(--m) : nums2.at(--n);
            } else if (n > 0) {
                nums1.at(i) = nums2.at(--n);
            } else
                break;
        }
    }
};