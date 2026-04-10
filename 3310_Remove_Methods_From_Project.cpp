class Solution {
public:
    void dfs_k(int cur, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[cur]) return;
        visited[cur] = true;

        for (auto next : adj[cur])
            dfs_k(next, adj, visited);
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& in : invocations)
            adj[in[0]].push_back(in[1]);

        vector<bool> touched_by_k(n, false);
        dfs_k(k, adj, touched_by_k);

        // If ∃ an edge from outside into k’s component,
        // then nothing can be erased.
        for (auto& in : invocations) {
            int u = in[0], v = in[1];
            if (!touched_by_k[u] && touched_by_k[v]) {
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i)
            if (!touched_by_k[i])
                ret.push_back(i);

        return ret;
    }
};
