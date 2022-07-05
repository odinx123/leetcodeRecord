class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            bool row[9] = {0};
            bool column[9] = {0};
            for (int j = 0; j < board.size(); ++j) {
                if (i % 3 == 0 && j % 3 == 0 && !search(j, i, board))
                    return false;

                if (board[i][j] != '.' && column[board[i][j]-49])
                    return false;
                else if (board[i][j] != '.')
                    column[board[i][j]-49] = true;

                if (board[j][i] != '.' && row[board[j][i]-49])
                    return false;
                else if (board[j][i] != '.')
                    row[board[j][i]-49] = true;
            }
        }
        
        return true;
    }
    
    bool search(int x, int y, const vector<vector<char>> &board) {
        int number[9] = {0};
        for (int i = 0; i < 9; ++i) {
            char num = board[y+i/3][x+i%3];

            if (num != '.' && ++number[num-48-1] > 1)
                return false;
        }
        return true;
    }
};