class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre = -prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int sell = pre + prices[i];  // 當天賣的價錢
            pre = -prices[i];
            if (sell > 0) {
                ans += sell;
            }
        }

        return ans;
    }
};