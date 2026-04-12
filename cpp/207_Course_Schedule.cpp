class Solution {
public:
    bool dfs(int cur, vector<bool>& seen_l, vector<bool>& seen_g, vector<vector<int>>& adj)
    {
        if (seen_l[cur]) return false;
        if (seen_g[cur]) return true;

        seen_l[cur] = true;
        for (auto& next : adj[cur])
            if (!dfs(next, seen_l, seen_g, adj)) return false;

        seen_l[cur] = false;
        seen_g[cur] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(numCourses);
        for (auto& e : prereqs)
            adj[e[1]].push_back(e[0]);

        vector<bool> seen_g(numCourses, false);
        vector<bool> seen_l(numCourses, false);

        for (int i = 0; i < numCourses; ++i)
            if (!seen_g[i] && !dfs(i, seen_l, seen_g, adj))
                return false;

        return true;
    }
};

