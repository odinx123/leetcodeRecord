class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int height = matrix.size(), width = matrix.front().size();
        int y = 0, x = 0, state = 0, rbeg = 1, cbeg = 0;
        int size = width * height;
        
        while (--size >= 0) {
            if (state == 0) {
                ans.push_back(matrix[y][x]);
                if (++x == width)
                    ++state, ++y, --x, --width;
            } else if (state == 1) {
                ans.push_back(matrix[y][x]);
                if (++y == height)
                    ++state, --x, --y, --height;
            } else if (state == 2) {
                ans.push_back(matrix[y][x]);
                if (--x < cbeg)
                    ++state, --y, ++x, ++cbeg;
            } else if (state == 3) {
                ans.push_back(matrix[y][x]);
                if (--y < rbeg)
                    state = 0, ++x, ++y, ++rbeg;
            }
        }
        
        return ans;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};