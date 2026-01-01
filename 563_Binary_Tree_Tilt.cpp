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
    int dfs(TreeNode* root, int tilt, int* ret)
    {
        if (!root) return 0;
       
        int l_sum = dfs(root->left, tilt);
        int r_sum = dfs(root->right, tilt);

        *ret += abs(l_sum - r_sum); 

        return root->val + l_sum + r_sum;
    }
    int findTilt(TreeNode* root) {
        int ret = 0;
        dfs(root, 0, &ret);
        return ret;
    }
};
