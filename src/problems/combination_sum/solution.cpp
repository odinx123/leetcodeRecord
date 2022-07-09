class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());  // 排序後
        
        backtracking(0, temp, candidates, target, ans);
        
        return ans;
    }
    
    void backtracking(int pos, vector<int> &temp, vector<int>& candidates, int target, vector<vector<int>>& combinations) {
        // Base case
        if (target == 0) {  // 如果達到target就加入答案。
            combinations.push_back(temp);
            return;
        }
        
        // 如果這個位置已經小於0，那就不用判斷他跟其他的組合，因為沒有意義(數字也沒有負數)
        if (target-candidates.at(pos) < 0) return;
        
        // Recursion relation
        for (int i = pos; i < candidates.size(); ++i) {
            temp.push_back(candidates.at(i));
            backtracking(i, temp, candidates, target-candidates.at(i), combinations);
            // 成功加入答案或是沒有都會到這邊
            // 判斷下個i的狀況，如果已經沒有則會回到上個遞迴
            // 要把這次push進去的數字刪掉，因為已經判斷過了這個數字在這邊的所有狀況
            temp.pop_back();
        }
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};