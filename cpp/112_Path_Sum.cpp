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
    bool p(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right)
            return targetSum == root->val;

        int rem = targetSum - root->val;
        return p(root->left, rem) || p(root->right, rem);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return p(root, targetSum);
    }
};
