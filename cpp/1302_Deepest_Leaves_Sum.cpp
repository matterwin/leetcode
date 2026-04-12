// https://leetcode.com/problems/deepest-leaves-sum/description/

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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        uint64_t ret = 0;
        while (!q.empty())
        {
            int sz = q.size();
            int lvl_size = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode* cur = q.front();
                q.pop();

                lvl_size += cur->val;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ret = lvl_size;
        }

        return ret;
    }
};
