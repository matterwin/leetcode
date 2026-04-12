class Solution {
public:
    bool dfs(int u, vector<int>& colors, vector<vector<int>>& graph, int color) 
    {
        if (colors[u] != -1) 
            return colors[u] == color;

        colors[u] = color;

        for (int v : graph[u]) 
            if (!dfs(v, colors, graph, 1 - color);
                return false;

        return true; 
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i)
            if (!dfs(i, colors, graph, 0);
                return false;
        return true;
    }
};
