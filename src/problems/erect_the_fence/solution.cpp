class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;

        sort(trees.begin(), trees.end(), [](vector<int> &p1, vector<int> &p2) {
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });

        int pos = 0;
        for (int i = 0; i < trees.size(); ++i) {  // 上半部
            while (pos > 1) {
                if (Area(ans[pos - 2], ans[pos - 1], trees[i]) > 0) {
                    ans.pop_back();
                    --pos;
                } else
                    break;
            }
            ans.emplace_back(trees[i]);
            ++pos;
        }

        int newOrg = pos-1;
        for (int i = trees.size()-2; i >= 0; --i) {  // 下半部(除去最後一格)
            while (pos >= newOrg+2) {
                if (Area(ans[pos - 2], ans[pos - 1], trees[i]) > 0) {
                    ans.pop_back();
                    --pos;
                } else
                    break;
            }
            ans.emplace_back(trees[i]);
            ++pos;
        }

        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.resize(it - ans.begin());

        return ans;
    }

    double Area(vector<int> &org, vector<int> &p1, vector<int> &p2) {
        return 0.5 * ((org[0] * p1[1] + p1[0] * p2[1] + p2[0] * org[1])
        - (p1[0] * org[1] + p2[0] * p1[1] + org[0] * p2[1]));
    }
};