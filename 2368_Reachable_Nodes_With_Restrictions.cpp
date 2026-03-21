class Solution {
public:
    void dfs(int cur, vector<bool>& visited, vector<bool>& restricted, vector<vector<int>>& adj) 
    {
        if (visited[cur] || restricted[cur]) return;
        visited[cur] = true;

        for (auto next : adj[cur])
            dfs(next, visited, restricted, adj);
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restrictedList) 
    {
        vector<vector<int>> adj(n);
        for (auto &e : edges) 
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<bool> restricted(n, false);
        for (int r : restrictedList) restricted[r] = true;

        dfs(0, visited, restricted, adj);

        int ret = 0;
        for (bool b : visited) if (b) ret++;
        return ret;
    }
};
