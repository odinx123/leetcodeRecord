class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int cur, n1, n2;
        cur = min(nums1[n1=0], nums2[n2=0]);

        while (n1 < nums1.size() && n2 < nums2.size()) {
            if (nums1[n1] == nums2[n2]) {
                cur = nums1[n1];
                while (n1 < nums1.size() && nums1[n1] == cur) ++n1;
                while (n2 < nums2.size() && nums2[n2] == cur) ++n2;
            }
            else if (nums1[n1] < nums2[n2]) {
                cur = nums1[n1++];
                ans[0].push_back(cur);
                while (n1 < nums1.size() && nums1[n1] == cur) ++n1;
            }
            else {
                cur = nums2[n2++];
                ans[1].push_back(cur);
                while (n2 < nums2.size() && nums2[n2] == cur) ++n2;
            }
        }

        // cur不怕會被其中一個換掉，因為兩個for只會跑一個
        for (int i = n1; i < nums1.size(); ++i) {
            if (nums1[i] != cur) {
                cur = nums1[i];
                ans[0].push_back(nums1[i]);
            }
        }
        for (int i = n2; i < nums2.size(); ++i) {
            if (nums2[i] != cur) {
                cur = nums2[i];
                ans[1].push_back(nums2[i]);
            }
        }

        return ans;
    }
};