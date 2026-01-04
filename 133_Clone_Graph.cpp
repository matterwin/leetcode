/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& visited)
    {
        if (!node) return;
        if (visited.count(node)) return;

        Node* clone = new Node(node->val);
        visited[clone] = clone;

        for (Node* n : node->neighbors)
        {
            dfs(n, visited);
            clone->neighbors.push_back(visited[n]);
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        dfs(node, visited);
        return visited[node];
    }
};

