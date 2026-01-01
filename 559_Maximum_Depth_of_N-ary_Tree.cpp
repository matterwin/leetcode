/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int mx = 0;

    void dfs(Node* root, int cur_depth) {
        if (!root) return;

        mx = max(mx, cur_depth);

        for (Node* child : root->children)
            dfs(child, cur_depth + 1);
    }

    int maxDepth(Node* root) {
        if (!root) return 0;
        dfs(root, 1);
        return mx;
    }
};

