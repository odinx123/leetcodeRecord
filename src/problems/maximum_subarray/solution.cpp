class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], preSubMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int currentNum = nums.at(i);
            // 如果前一個子序列最大直小於等於0，代表新子序列的開始(加上前面無意義)
            // 前面子序列<0越加越小，所以取最大值可以找到新的開始
            preSubMax = max(currentNum, preSubMax+currentNum);
            
            // 判斷新的子序列跟之前統計過最大子序列哪個比較大，不用記錄子序列位置
            maxSoFar = max(preSubMax, maxSoFar);
        }
        
        return maxSoFar;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};