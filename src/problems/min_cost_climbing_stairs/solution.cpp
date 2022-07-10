class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) { 
        cost.push_back(0);
        for (int i = 2; i < cost.size(); ++i)
            cost.at(i) += min(cost.at(i-1), cost.at(i-2));
        
        return cost.back();
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};