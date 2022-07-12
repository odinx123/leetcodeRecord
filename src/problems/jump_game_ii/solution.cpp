class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minStep(nums.size());
        deque<pair<int, int>> priQueue(1, {0, nums.at(0)});
        minStep.at(0) = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            minStep.at(i) = minStep[priQueue.front().first] + 1;
            
            // 只要把過期的步驟刪掉，每次最前面都會是可以碰的當前位置的最小步數
            while (!priQueue.empty() && i-priQueue.front().first >= priQueue.front().second)
                priQueue.pop_front();
            
            priQueue.push_back({i, nums.at(i)});
        }
        
        return minStep.back();
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};