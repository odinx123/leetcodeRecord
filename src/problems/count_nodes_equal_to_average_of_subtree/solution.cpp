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
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        sumNode(root, cnt);

        return cnt;
    }

    pair<int, int> sumNode(TreeNode* root, int& cnt) {
        // Base Case
        if (root == nullptr) return {0, 0};

        // Recursion relation
        pair<int, int> sum{root->val, 1};  // 自己當前value跟次數都要計算
        pair<int, int> lptr = sumNode(root->left, cnt);
        pair<int, int> rptr = sumNode(root->right, cnt);
        
        sum.first += lptr.first + rptr.first;
        sum.second += lptr.second + rptr.second;

        cnt += root->val == sum.first / sum.second;

        return sum;
    }
};