class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<int>> mtx(k + 1, vector<int>(n, INT_MIN));
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        for (int v = 0; v < n; ++v)
            mtx[0][v] = 0;

        for (int i = 0; i < k; ++i) {
            for (int u = 0; u < n; ++u) {
                if (mtx[i][u] == INT_MIN) continue;
                for (auto [v, w] : adj[u]) {
                    if (w >= t) continue;
                    mtx[i + 1][v] = max(mtx[i + 1][v], mtx[i][u] + w);
                }
            }
        }

        int ans = INT_MIN;
        for (int v = 0; v < n; ++v)
            ans = max(ans, mtx[k][v]);
        return ans;
    }
};
