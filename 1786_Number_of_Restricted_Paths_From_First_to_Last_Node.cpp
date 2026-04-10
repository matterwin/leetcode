class Solution {
    const int MOD = 1e9 + 7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int src = n - 1;
        q.push({0, src});
        dist[src] = 0;

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (dist[u] < d) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int u) -> int {
            if (u == src) return 1;
            if (memo[u] != -1) return memo[u];

            int total = 0;
            for (auto [v, w] : adj[u])
                if (dist[u] > dist[v]) 
                    total = (total + dfs(v)) % MOD;
            return memo[u] = total;
        };

        return dfs(0);
    }
};
