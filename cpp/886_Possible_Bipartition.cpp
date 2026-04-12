class Solution {
public:
    bool dfs(int cur, vector<vector<int>>& adj, vector<int>& colors, int color)
    {
        if (colors[cur] != -1)
            return colors[cur] == color;

        colors[cur] = color;
        for (int next : adj[cur])
            if (!dfs(next, adj, colors, 1 - color))
                return false;

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> colors(n + 1, -1);      
        vector<vector<int>> adj(n + 1);

        for (auto p : dislikes)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        for (int node = 1; node <= n; ++node)
            if (colors[node] == -1)
                if (!dfs(node, adj, colors, 0))
                    return false;

        return true;        
    }
};

