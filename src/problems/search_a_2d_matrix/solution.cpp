class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size()-1, mid = (up+down)/2;
        
        while (up <= down) {
            if (target < matrix.at(mid).front()) {
                down = mid - 1;
            } else if (target > matrix.at(mid).back()) {
                up = mid + 1;
            } else if (binary_search(matrix.at(mid).begin(), matrix.at(mid).end(), target)){
                return true;
            } else
                return false;
            mid = (up+down)/2;
        }
        
        return false;
    }
};