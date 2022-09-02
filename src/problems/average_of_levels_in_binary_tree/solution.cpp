/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<pair<long long, int>> data;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        
        vector<double> ans(data.size());
        for (int i = 0; i < data.size(); ++i)
            ans[i] = (double)data[i].first / data[i].second;
        
        return ans;
    }
    
    void dfs(TreeNode* currentNode, int level) {
        // Base case
        if (currentNode == nullptr) return;
        
        // Recursion relation
        if (level >= data.size())
            data.push_back({currentNode->val, 1});
        else {
            data[level].first += currentNode->val;
            ++data[level].second;
        }
        
        dfs(currentNode->left, level+1);
        dfs(currentNode->right, level+1);
    }
};