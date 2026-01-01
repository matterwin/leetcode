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
    int ret = -1;
    uint64_t min_1 = 1ULL << 33;
    uint64_t min_2 = min_1;

    void dfs(TreeNode* root)
    {
        if (!root) return;
        if (root->val < min_1)
        {
            min_2 = min_1;
            min_1 = root->val;
        }
        else if (root->val < min_2 && root->val > min_1)
            min_2 = root->val;

        dfs(root->left);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);

        if (min_2 == 1ULL << 33) return -1;
        return min_2;
    }
};
};
