class Solution {
    int m = 0;
    int n = 0;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        // 如果dfs有走訪到那個位置，代表那個位置可以留到太平洋或是大西洋(兩著分開判斷)
        vector<vector<bool>> Pacific(m, vector<bool>(n));
        vector<vector<bool>> Atlantic(m, vector<bool>(n));
        
        for (int i = 0; i < n; ++i)
            dfs(heights, i, 0, Pacific);
        for (int i = 0; i < m; ++i)
            dfs(heights, 0, i, Pacific);
        
        for (int i = 0; i < n; ++i)
            dfs(heights, i, m-1, Atlantic);
        for (int i = 0; i < m; ++i)
            dfs(heights, n-1, i, Atlantic);
        
        vector<vector<int>> results;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (Pacific[i][j] && Atlantic[i][j])
                    results.push_back({i, j});
            }
        }
        
        return results;
    }
    
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& state) {
        // Base case
        if (state[y][x]) return;
        
        // Recursion relation
        state[y][x] = true;
        if (y+1 < m && heights[y][x] <= heights[y+1][x])
            dfs(heights, x, y+1, state);
        if (y-1 >= 0 && heights[y][x] <= heights[y-1][x])
            dfs(heights, x, y-1, state);
        if (x+1 < n && heights[y][x] <= heights[y][x+1])
            dfs(heights, x+1, y, state);
        if (x-1 >= 0 && heights[y][x] <= heights[y][x-1])
            dfs(heights, x-1, y, state);
    }
};