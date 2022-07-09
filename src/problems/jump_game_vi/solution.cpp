// 每次都從index0的位置開始，要找加總到nums.size()-1位置的最大值
// 若是每次都可以跳1~k個step，那找出加總之後的最大值
class Solution {
public:
    inline int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());  // to store the number that already calculator
        // init
        deque<int> priQueue(1, 0);  // 前面元素也需要刪除
        dp.at(0) = nums.at(0);
        
        // 最開始當前最大值就是nums的第一個位置
        for (int i = 1; i < nums.size(); ++i) {
            // dp每次加總都會是前面加總的值加上當前位置的值的最大值，最後一個元素一定要加
            dp.at(i) = dp[priQueue.front()] + nums.at(i);
            // 前面元素可以摸到的k範圍，當前出現的也可以(而當前的值又比較大)，所以可以捨去之前的元素值
            while (!priQueue.empty() && dp.at(i) >= dp[priQueue.back()]) priQueue.pop_back();
            // 把超過範圍的值刪除，因為他已經超過每次可以跳k個step的範圍(對接下來沒幫助)
            // 每次push進去的值一定在最後的位置(小於的被刪除，大於的在前面)，代表最前面的一定是最老的值
            // 而且每輪又都判斷一次，所以最老的值一定可以刪掉(用if就好不用while)
            if (!priQueue.empty() && i - priQueue.front() >= k)  // priQueue是儲存位置
                priQueue.pop_front();

            priQueue.push_back(i);  // 比他小的都被刪掉了->所以會在他該待的位置
        }
        
        return dp.back();
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};