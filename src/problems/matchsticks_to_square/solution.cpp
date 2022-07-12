class Solution {
    vector<int> side{0, 0, 0, 0};
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (const int &i : matchsticks)
            sum += i;
        if (!sum || sum % 4 != 0 || matchsticks.size() < 4) return false;
        sum /= 4;
        
        sort(matchsticks.rbegin(), matchsticks.rend());  // 如果結果是false，可以快點得到
        
        if (matchsticks.at(0) > sum) return false;
        
        return backtracking(matchsticks, 0, sum); // 正方形邊長一定是在sum/4的情況下
    }
    
    bool backtracking(vector<int>& ticks, int pos, const int &target) {
        // Base case
        if (pos >= ticks.size())
            return side[0] == side[1] && side[1] == side[2] && side[2] == target;
        
        // Recursion relation
        // 每個pos(每個遞迴中)都會測試side 1~4 可不可以放
        for (int i = 0; i < 4; ++i) {  // 4個邊
            // 每個火材都要用(所以太大只能換下個邊試試看)
            if (side.at(i) + ticks.at(pos) > target) continue;  // 太大就換下個邊
            
            // 【重點】
            int j;
            for (j = 0; j < i; ++j)
                if (side.at(j) == side.at(i))
                    break;
            if (j != i) continue;
            // 如果第i邊的長度跟之前的相同，那代表已經判斷過了(pos一樣)
            // 而沒有結束代表答案是錯誤的，所以直接換到下個火材的位置
            // 而這樣可以少很多無用遞迴
            
            side.at(i) += ticks.at(pos);
            if (backtracking(ticks, pos+1, target)) return true;
            side.at(i) -= ticks.at(pos);  // 回朔
        }
        
        return false;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};