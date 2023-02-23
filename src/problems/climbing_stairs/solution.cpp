class Solution {
public:
    int climbStairs(int n) {
        int pre1 = 1, pre2 = 2, ans = n;
        for (int i = 2; i < n; ++i) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }

        return ans;
    }
};