class Solution {
public:
    int dfs(int cur, vector<vector<int>>& adj, vector<int>& ans, vector<int>& quiet)
    {
        if (ans[cur] != -1) return ans[cur];

        ans[cur] = cur;
        
        for (auto v : adj[cur])
        {
            int cand = dfs(v, adj, ans, quiet);
            if (quiet[cand] < quiet[ans[cur]])  // compare with current best
                ans[cur] = cand;
        }

        return ans[cur]; 
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);

        // node points to nodes less richer than themselves
        vector<vector<int>> adj(n);
        for (auto p : richer)
            adj[p[1]].push_back(p[0]);

        for (int i = 0; i < n; ++i)
            dfs(i, adj, ans, quiet);

        return ans;
    }
};
