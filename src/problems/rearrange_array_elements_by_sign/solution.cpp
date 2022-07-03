class Solution {
public:
    // Solution() {
    //     std::ios_base::sync_with_stdio(false);
    //     std::cin.tie(nullptr);
    // }
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        
        auto p2 = stable_partition(nums.begin(), nums.end(), [] (const int &n) {
            return n >= 0;
        });
        
        auto end = p2;
        for (auto it = nums.begin(); it != end; ++it) {
            ans.push_back(*it);
            ans.push_back(*p2++);
        }

        return ans;
    }
};