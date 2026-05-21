#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> memo;

    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {nullptr};

        if (memo.count({l, r})) return memo[{l, r}];

        vector<TreeNode*> trees;

        for (int root = l; root <= r; ++root) {

            auto leftTrees = build(l, root - 1);
            auto rightTrees = build(root + 1, r);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {

                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;

                    trees.push_back(node);
                }
            }
        }

        return memo[{l, r}] = trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
