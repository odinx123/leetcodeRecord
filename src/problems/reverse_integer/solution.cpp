class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        for (int i = 0; x != 0; x/=10) {
            // 加x%10不用判斷是因為input限制在32bit的INT裡面
            // 所以214748364(INT_MAX/10)是可以過得，那麼ans最多跟他一樣大
            if (INT_MAX/10 < ans || INT_MIN/10 > ans)
                return 0;
            ans = ans*10 + x%10;
        }

        return ans;
    }
};