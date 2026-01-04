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
    bool evaluateTree(TreeNode* root) {
        if (!root) return true;       

        bool lhs = evaluateTree(root->left);
        bool rhs = evaluateTree(root->right);
        
        if (!root->left && !root->right)
            return root->val;

        else if (root->val == 2)
            return lhs || rhs;
        else 
            return lhs && rhs;
    }
};
