#include <cstdio>
#include <bits/stdc++.h>
#include <stdio.h>
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
    void trav(TreeNode* root, int* ret, bool is_left)
    {
        if (!root) return;
        if (!root->left && !root->right && is_left)
            *ret += root->val;
        trav(root->left, ret, true);
        trav(root->right, ret, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ret = 0;
        trav(root, &ret, false); 
        return ret;
    }
};

