class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string r;
        vector<string> ans;

        dfs(ans, 0, 0, n, r);

        return ans;
    }

    void dfs(vector<string>& ans, int l, int r, const int& n, string& res) {
        // Base case
        if (r > l || l > n) return;
        if (l == r && r == n) {
            ans.push_back(res);
            return;
        }

        // Recursion relation
        for (short i = 0; i < 2; ++i) {
            if (i == 0) {  // i == 0代表左括弧
                res.push_back('(');
                dfs(ans, l+1, r, n, res);
            } else { // i == 1代表右括弧
                res.push_back(')');
                dfs(ans, l, r+1, n, res);
            }
            res.pop_back();
        }
    }
};