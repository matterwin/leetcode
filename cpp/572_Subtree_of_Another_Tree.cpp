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
    bool dfs(TreeNode* r1, TreeNode* r2)
    {
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;

        return r1->val == r2->val && dfs(r1->left, r2->left, og_r2)
            && dfs(r1->right, r2->right, og_r2);
    }
    bool isSubtree(TreeNode* r1, TreeNode* r2) {
        if (!r1) return false;
        return dfs(r1, r2) || isSubtree(r1->left, r2) || isSubtree(r1->right, r2);
    }
};


