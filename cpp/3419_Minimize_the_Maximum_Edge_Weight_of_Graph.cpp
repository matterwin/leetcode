class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);

        // reverse edges
        for (auto& e : edges)
            adj[e[1]].push_back({e[0], e[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                int newCost = max(d, w);
                if (dist[v] > newCost) {
                    dist[v] = newCost;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int ans = 0;
        for (int d : dist) {
            if (d == INT_MAX) return -1;
            ans = max(ans, d);
        }

        return ans;
    }
};
