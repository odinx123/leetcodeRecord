class Solution {
public:
    string convertToTitle(int columnNumber) {
        string column;
        
        while (columnNumber) {
            if (columnNumber % 26 == 0) {
                column.push_back('Z');
                columnNumber = columnNumber / 26 - 1;
            } else {
                column.push_back(columnNumber % 26 + 'A' - 1);
                columnNumber /= 26;
            }
        }
        
        reverse(column.begin(), column.end());
        
        return column;
    }
};