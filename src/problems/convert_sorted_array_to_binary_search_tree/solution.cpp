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
    TreeNode* root = nullptr;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        insert(0, nums.size()-1, nums);
        return root;
    }
    
    TreeNode* insert(int beg, int end, vector<int>& nums) {
        int mid = (beg+end)/2;
        TreeNode* currentNode = new TreeNode(nums.at(mid));
        
        if (root == nullptr)
            root = currentNode;
        
        if (beg != end) {
            if (beg == mid) {
                currentNode->right = new TreeNode(nums.at(mid+1));
            } else {
                currentNode->left = insert(beg, mid-1, nums);
                currentNode->right = insert(mid+1, end, nums);
            }
        }
        
        return currentNode;
    }
};