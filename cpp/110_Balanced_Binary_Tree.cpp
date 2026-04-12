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
    int getDepth(TreeNode* root, bool* flag)
    {
        if (!root) return 0;

        int left_depth = getDepth(root->left, flag); 
        int right_depth = getDepth(root->right, flag); 

        if (abs(left_depth - right_depth) > 1) *flag = false;

        return 1 + left_depth + right_depth;
    }
    bool isBalanced(TreeNode* root) {
        fast;
        if (!root) return true;
        bool flag = true;
        getDepth(root, &flag);
        return flag;
    }
};

