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
    int dfs(TreeNode* root, int low, int high) 
    {
        if (!root) return 0;

        int left = 0, right = 0;
        if (root->val < low)
        {
            right = dfs(root->right, low, high);
            return right;
        }
        if (root->val > high)
        {
            left = dfs(root->left, low, high);
            return left;
        }
        if (left == 0)
            left = dfs(root->left, low, high);
        if (right == 0)
            right = dfs(root->right, low, high);

        return root->val + left + right;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};
