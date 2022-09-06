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
    TreeNode* pruneTree(TreeNode* root) {
        if (!traversal(root)) {
            delete root;
            root = nullptr;
        }
        
        return root;
    }
    
    bool traversal(TreeNode* currentNode) {
        // Base case
        if (currentNode == nullptr) return false;

        // Recursion relation
        bool left = traversal(currentNode->left);
        bool right = traversal(currentNode->right);
        

        if (!left && currentNode->left != nullptr) {
            delete currentNode->left;
            currentNode->left = nullptr;
        }
        if (!right && currentNode->right != nullptr) {
            delete currentNode->right;
            currentNode->right = nullptr;
        }

        if (!left && !right && currentNode->val != 1)
            return false;
        return true;
    }
};