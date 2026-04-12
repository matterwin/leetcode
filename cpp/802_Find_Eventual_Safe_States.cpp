class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& state) {
        if (state[u] != 0)
            return state[u] == 2;  // already classified

        state[u] = 1; // visiting

        for (int v : graph[u]) 
            if (!dfs(v, graph, state))
                return false; // one unsafe in path; abort.

        state[u] = 2; // safe
        return true; // node is safe
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=safe
        vector<int> ret;

        for (int i = 0; i < n; ++i) 
        {
            if (dfs(i, graph, state))
                ret.push_back(i);
        }

        return ret;
    }
};

