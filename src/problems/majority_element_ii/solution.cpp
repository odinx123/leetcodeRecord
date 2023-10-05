class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr;

        sort(nums.begin(), nums.end());

        int cnt = 1, gap = nums.size() / 3;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) ++cnt;
            else {
                if (cnt > gap) arr.push_back(nums[i-1]);

                cnt = 1;
            }
        }
        if (cnt > gap)
            arr.push_back(nums.back());

        return arr;
    }
};