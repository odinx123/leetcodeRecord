class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        // 每個5的次方都有可能讓階乘尾數多一個0
        // 除i有大於1才有可能再多
        for (int i = 5; n/i >= 1; i *= 5)
            ans += (n / i);
        
        return ans;
    }
};