class Solution {
public:
    bool winnerOfGame(string colors) {
        // At least three continuous literals.
        unordered_map<char, int> move_times;
        int cnt = 1;

        for (int i = 1; i < colors.size(); ++i) {
            if (colors[i] == colors[i-1]) {
                ++cnt;
            } else {
                if (cnt > 2)
                    move_times[colors[i-1]] += cnt - 2;
                
                cnt = 1;
            }
        }

        if (cnt > 2)
            move_times[colors.back()] += cnt - 2;

        return move_times['A'] > move_times['B'];
    }
};