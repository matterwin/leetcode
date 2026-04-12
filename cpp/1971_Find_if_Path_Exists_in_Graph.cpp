class Solution {
public:
    void dfs(vector<vector<int>>& adj, int dest, bool* ret, int cur_vert, vector<bool>* seen)
    {
        (*seen)[cur_vert] = true;
        if (cur_vert == dest)
        {
            *ret = true;
            return;
        }

        for (int next : adj[cur_vert])
            if (!(*seen)[next]) dfs(adj, dest, ret, next, seen);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> seen(n, false);
        bool ret = false;
        dfs(adj, destination, &ret, source, &seen);
        return ret;
    }
};

