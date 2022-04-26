class Solution {
   public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<vector<int>> n(100);
        vector<vector<int>> pos(100);
        hash(nums, n, pos);
        for (int i = 0; i < nums.size(); ++i) {
            int ans = target - nums.at(i);
            int len = n.at(abs(ans%100)).size();
            while (len != 0) {
                if (pos.at(abs(ans%100))[len-1] != i && n.at(abs(ans%100))[len-1] == ans)
                    return {i, pos.at(abs(ans%100))[len-1]};
                --len;
            }
        }
        return nums;
    }
    inline void hash(const vector<int> &nums, vector<vector<int>> &vec, vector<vector<int>> &pos);
};
void Solution::hash(const vector<int> &nums, vector<vector<int>> &n, vector<vector<int>> &pos) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        n.at(abs(nums.at(i)%100)).emplace_back(nums[i]);
        pos.at(abs(nums.at(i)%100)).emplace_back(i);
    }
}