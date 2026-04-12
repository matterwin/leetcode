class Solution {
public:
    void dfs(int cur,
             vector<vector<int>>& adj,
             vector<int>& ans,
             vector<bool>& seen)
    {
        seen[cur] = true;

        int used = 0;
        for (int next : adj[cur])
            if (ans[next] != 0)
                used |= 1 << ans[next];

        for (int c = 1; c <= 4; c++) 
        {
            if ((used & (1 << c)) == 0) 
            {
                ans[cur] = c;
                break;
            }
        }

        for (int next : adj[cur])
            if (!seen[next])
                dfs(next, adj, ans, seen);
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<bool> seen(n + 1, false);

        for (auto& path : paths)
        {
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }

        for (int i = 1; i <= n; i++)
            if (!seen[i])
                dfs(i, adj, ans, seen);

        ans.erase(ans.begin());
        return ans;
    }
};

