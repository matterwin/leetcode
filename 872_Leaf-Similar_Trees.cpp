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
    int inorder(TreeNode* root, int* leaves, int i)
    {
        if (!root) return i;

        i = inorder(root->left, leaves, i);

        if (!root->left && !root->right)
            leaves[i++] = root->val;

        return inorder(root->right, leaves, i);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int leaves1[200], leaves2[200];
        memset(leaves1, 0, sizeof(leaves1));
        memset(leaves2, 0, sizeof(leaves2));

        int i1 = 0, i2 = 0;
        i1 = inorder(root1, leaves1, i1);
        i2 = inorder(root2, leaves2, i2);

        if (i1 != i2) return false;
        for (int i = 0; i < i1; ++i)
        {
            if (leaves1[i] != leaves2[i])
                return false;
        }
        return true;
    }
};



