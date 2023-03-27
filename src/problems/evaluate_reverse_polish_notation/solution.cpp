class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> val;
        for (int i = 0; i < tokens.size(); ++i) {
            int pos = val.size()-1;
            if (tokens[i] == "+") {
                val[pos-1] = val[pos-1] + val[pos];
                val.pop_back();
            } else if (tokens[i] == "-") {
                val[pos-1] = val[pos-1] - val[pos];
                val.pop_back();
            } else if (tokens[i] == "*") {
                val[pos-1] = val[pos-1] * val[pos];
                val.pop_back();
            } else if (tokens[i] == "/") {
                val[pos-1] = val[pos-1] / val[pos];
                val.pop_back();
            } else {
                val.push_back(stoi(tokens[i]));
            }
        }

        return val.back();
    }
};