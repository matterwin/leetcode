class Solution {
public:
    void dfs(int cur, int stop, vector<vector<int>>& adj, vector<vector<int>>& ret, vector<int> path)
    {
        if (cur == stop)
        {
            ret.push_back(path);
            return;
        }
        for (auto& next : adj[cur])
        {
            path.push_back(next);
            dfs(next, stop, adj, ret, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ret;
        vector<int> path;
        path.push_back(0);
        dfs(0, n - 1, graph, ret, path);
        return ret;
    }
};


