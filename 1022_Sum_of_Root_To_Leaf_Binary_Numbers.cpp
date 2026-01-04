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
    void dfs(TreeNode* root, int cur, int* sum)
    {
        if (!root) return;
        // triggers counting of digits
        // when met at msb
        cur = cur * 2 + root->val;
        if (!root->left && !root->right)
        {
            *sum += cur;
            return;
        }
        dfs(root->left, cur, sum);
        dfs(root->right, cur, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, &sum);
        return sum;
    }
};

