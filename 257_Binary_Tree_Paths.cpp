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
    void dfs(TreeNode* root, string path, vector<string>* ret)
    {
        if (!root) return;
        path += to_string(root->val);

        if (!root->left && !root->right)
        {
            (*ret).push_back(path);
            return;
        }

        dfs(root->left, path + "->", ret);
        dfs(root->right, path + "->", ret);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> ret;
        dfs(root, "", &ret);
        return ret;
    }
};


