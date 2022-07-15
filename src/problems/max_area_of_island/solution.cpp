class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        queue<int> pos;
        vector<bool> used(grid.size()*grid.at(0).size());
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.at(i).size(); ++j) {
                if (grid[i][j] == 0 || used.at(i*grid.at(i).size() + j)) continue;
                pos.push(i*grid.at(i).size() + j);
                
                int currentMax = 0;
                while (!pos.empty()) {
                    int currentPos = pos.front();
                    pos.pop();
                    
                    if (used.at(currentPos)) continue;
                    
                    ++currentMax;
                    
                    if (isRightHave(grid, currentPos) && !used.at(currentPos))
                        pos.push(currentPos+1);
                    if (isLeftHave(grid, currentPos) && !used.at(currentPos))
                        pos.push(currentPos-1);
                    if (isUpHave(grid, currentPos))
                        pos.push(currentPos-grid[i].size());
                    if (isDownHave(grid, currentPos) && !used.at(currentPos))
                        pos.push(currentPos+grid[i].size());
                    used.at(currentPos) = true;
                }
                maxArea = max(maxArea, currentMax);
            }
        }
        
        return maxArea;
    }
    
    inline bool isRightHave(vector<vector<int>>& grid, int pos) {
        if ((pos + 1) % grid[0].size() == 0) return false;
        if (!grid[(int)pos/grid.at(0).size()][(int)pos%grid.at(0).size()+1]) return false;
        return true;
    }
    
    inline bool isLeftHave(vector<vector<int>>& grid, int pos) {
        if (pos%(int)grid.at(0).size()-1 < 0) return false;
        if (!grid[pos/grid.at(0).size()][pos%grid.at(0).size()-1]) return false;
        return true;
    }
    
    inline bool isUpHave(vector<vector<int>>& grid, int pos) {
        if (pos - (int)grid.at(0).size() < 0) return false;
        if (!grid[(int)pos/grid.at(0).size()-1][(int)pos%grid.at(0).size()]) return false;
        return true;
    }
    
    inline bool isDownHave(vector<vector<int>>& grid, int pos) {
        if (pos + (int)grid[0].size() >= grid.size()*grid[0].size()) return false;
        if (!grid[(int)pos/grid.at(0).size()+1][(int)pos%grid.at(0).size()]) return false;
        return true;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};