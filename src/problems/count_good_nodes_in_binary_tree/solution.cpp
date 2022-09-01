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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt, root->val);
        
        return cnt;
    }
    
    void dfs(TreeNode* currentNode, int& cnt, int maxSoFar) {
        // Base case
        if (currentNode == nullptr) return;
        
        // Recursion relation
        if (currentNode->val >= maxSoFar) {
            maxSoFar = currentNode->val;
            ++cnt;
        }
        
        dfs(currentNode->left, cnt, maxSoFar);
        dfs(currentNode->right, cnt, maxSoFar);
    }
};