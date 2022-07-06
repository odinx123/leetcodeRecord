class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        nums1.resize(size1+size2);
        
        // 網友解
        while (size1 + size2 > 0) {
            if (size1 > 0 && size2 > 0) {
                if (nums1.at(size1-1) > nums2.at(size2-1)) {
                    nums1.at(size1+size2-1) = nums1.at(size1-1);
                    --size1;
                } else {
                    nums1.at(size1+size2-1) = nums2.at(size2-1);
                    --size2;
                }
            } else if (size2 > 0) {
                nums1.at(size1+size2-1) = nums2.at(size2-1);
                --size2;
            } else {
                break;
            }
        }
        
        int n = nums1.size()/2;
        
        if (nums1.size()%2 != 0)
            return nums1.at(n);
        
        return double(nums1.at(n)+nums1.at(n-1))/2;
    }
};