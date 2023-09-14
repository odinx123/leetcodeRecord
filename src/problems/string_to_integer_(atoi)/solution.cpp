class Solution {
public:
    int myAtoi(string s) {
        int beg = s.find_first_not_of(' ');
        if (beg == -1) return 0;

        long ans = 0, sign = 1;

        if (s[beg] == '-'){
            sign = -1;
            ++beg;
        }
        else if (s[beg] == '+')
            ++beg;

        for (int i = beg; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans*10 + s[i]-'0';
                if (ans > INT_MAX) {
                    if (sign == -1) return INT_MIN;
                    else return INT_MAX;
                }
            }
            else {
                break;
            }
        }

        return ans * sign;
    }
};