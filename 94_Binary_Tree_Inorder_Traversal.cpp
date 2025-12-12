using namespace std;
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);

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
    void inorder(vector<int> *ret, TreeNode *root) {
        if (!root) return;

        inorder(ret, root->left);
        ret->push_back(root->val);
        inorder(ret, root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        fast;
        vector<int> ret;
        inorder(&ret, root);
        return ret;
    }
};

