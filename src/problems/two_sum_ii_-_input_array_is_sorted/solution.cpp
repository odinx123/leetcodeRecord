class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 太小左邊移動，太大右邊移動
        int l = 0, r = numbers.size()-1;

        // 一定有解，所以不會超過範圍
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l+1, r+1};
            }
            else if (sum > target){
                --r;
            }
            else {
                ++l;
            }
        }

        return {};
    }
};