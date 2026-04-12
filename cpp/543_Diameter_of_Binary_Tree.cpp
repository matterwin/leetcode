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
    int mx = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int ld = dfs(root->left);
        int rd = dfs(root->right);

        mx = max(mx, ld + rd);

        return max(ld, rd) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return mx;
    }
};

