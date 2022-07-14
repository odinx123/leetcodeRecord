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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> r;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> bfs;
        
        int currentLevel = 0;
        int prevLevel = 0;
        
        if (root) {
            bfs.push({root, 0});
            // r.push_back(root->val);
        }
        
        while (!bfs.empty()) {
            TreeNode* currentNode = bfs.front().first;
            int level = bfs.front().second;
            
            bfs.pop();
            
            // cout << level << " " << prevLevel << " " << r.size() << endl;
            
            if (level != prevLevel) {
                ans.push_back(r);
                r.clear();
                r.push_back(currentNode->val);
            } else
                r.push_back(currentNode->val);
            
            if (currentNode->left)
                bfs.push({currentNode->left, level+1});
            if (currentNode->right)
                bfs.push({currentNode->right, level+1});
            prevLevel = level;
        }
        
        if (root)
            ans.push_back(r);
        
        return ans;
    }
    
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};