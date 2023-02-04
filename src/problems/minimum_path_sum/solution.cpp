class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int xSize = grid[0].size(), ySize = grid.size();
        vector<vector<int>> r(ySize, vector<int>(xSize, -1));

        return dfs(grid, r, xSize-1, ySize-1, 0);
    }

    int dfs(vector<vector<int>>& grid,
            vector<vector<int>>& r, int x, int y, int curSum) {
        // base case
        if (x < 0 || y < 0)
            return INT_MAX;  // 不需要的值
        if (r[y][x] > 0)  // 算過的
            return r[y][x];
        if (x == 0 && y == 0)
            return grid[y][x];

        // recursion relation
        int min_left = dfs(grid, r, x-1, y, curSum);  // move left.
        int min_up = dfs(grid, r, x, y-1, curSum);  // move up.

        return r[y][x] = min(min_left, min_up) + grid[y][x];
    }
};