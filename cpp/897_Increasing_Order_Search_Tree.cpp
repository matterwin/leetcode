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
    TreeNode* morris(TreeNode* root)
    {
        TreeNode* cur = root;
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* prev = dummy;

        while (cur)
        {
            if (cur->left)
            {
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur)
                    pred = pred->right;
                
                if (!pred->right)
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else 
                {
                    pred->right = nullptr; 

                    prev->right = cur;
                    cur->left = nullptr;
                    prev = cur;

                    cur = cur->right;
                }
            }
            else 
            {
                prev->right = cur;
                cur->left = nullptr;
                prev = cur;
                cur = cur->right;
            }
        }

        return dummy->right;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return morris(root);
    }
};

class Solution2 {
public:
    TreeNode* dfs(TreeNode* root)
    {
        if (!root) return nullptr;

        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);

        // attaches potentially new right subtree to root->right
        root->right = right;
    
        // no left, so we're done
        if (!left)
            return root;

        // left subtree exists, get rid of it
        root->left = nullptr;

        // get rightmost node
        TreeNode* p = left; 
        while (p->right)
            p = p->right;
        
        // root comes after
        p->right = root;
        return left;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root);
    }
};
