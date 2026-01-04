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
    TreeNode* parent_x = nullptr, *parent_y = nullptr;
    int depth_x = 0, depth_y = 0;
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int d)
    {
        if (!root) return;

        if (root->val == x)
        {
            depth_x = d;
            parent_x = parent;
        }
        else if (root->val == y)
        {
            depth_y = d;
            parent_y = parent;
        }

        dfs(root->left, root, x, y, d+1);
        dfs(root->right, root, x, y, d+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, x, y, 0);
        if (parent_x == parent_y) return false;
        if (depth_x != depth_y) return false;
        return true;
    }
};

