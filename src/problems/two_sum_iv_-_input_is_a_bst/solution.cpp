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
    unordered_map<int, int> hash;
public:
    bool findTarget(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<TreeNode*> data;
        data.reserve(16);
        data.push_back(root);
        
        while (!data.empty()) {
            TreeNode* currentNode = data.back();
            data.pop_back();
            
            if (hash.count(k-currentNode->val) > 0) return true;
            
            ++hash[currentNode->val];
            if (currentNode->left) data.push_back(currentNode->left);
            if (currentNode->right) data.push_back(currentNode->right);
        }
        
        return false;
    }
};