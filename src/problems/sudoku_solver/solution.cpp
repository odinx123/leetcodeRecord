class Solution {
    vector<int> dotPos;
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == '.') {
                    dotPos.push_back(i*9+j);
                    // cout << i*9+j << endl;
                }
            }
        }
        backtracking(0, board);
    }
    
    bool backtracking(int pos, vector<vector<char>>& board) {
        if (pos < dotPos.size()) {
            int x = dotPos.at(pos) % 9, y = dotPos.at(pos) / 9;
            for (char c = '1'; c <= '9'; ++c) {
                if (isValid(board, y, x, c)) {
                    board[y][x] = c;
                    if (backtracking(pos+1, board))
                        return true;
                }
            }
            board[y][x] = '.';
            return false;
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][col] == val)
                return false;
            
            if (board[row][i] == val)
                return false;

            if (board[row/3*3+i/3][col/3*3+i%3] == val)
                return false;
        }
        return true;
    }
};