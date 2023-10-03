class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int32_t cnt = 0;
        int32_t hash_map[101] = {0};

        // (n^2-n) / 2  梯形公式直接累加
        for (const auto& i : nums) {
            ++hash_map[i];
            cnt += hash_map[i] - 1;
            // or cnt += hash_map[i]++;
        }

        return cnt;
    }
};