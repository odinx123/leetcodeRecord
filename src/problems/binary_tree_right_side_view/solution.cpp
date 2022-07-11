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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*, int>> dfs;
        
        if (root)
            dfs.push({root, 0});

        int currentLevel = 0;
        TreeNode* currentNode = nullptr;
        while (!dfs.empty()) {
            int level = dfs.front().second;
            currentNode = dfs.front().first;
            
            if (level == currentLevel && currentNode) {
                ans.push_back(currentNode->val);
                ++currentLevel;
            }
            
            dfs.pop();

            if (currentNode->right)
                dfs.push({currentNode->right, level+1});
            if (currentNode->left)
                dfs.push({currentNode->left, level+1});
        }
        
        return ans;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};