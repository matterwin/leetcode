class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        const long long MOD = 1e9 + 7;
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto c : conversions)
            adj[c[0]].push_back({c[1], c[2]});

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);

        pq.push({1, 0});
        dist[0] = 1;

        while (!pq.empty()) {
            auto [d,v] = pq.top(); pq.pop();
            if (d > dist[v]) continue;

            for (auto [u,w] : adj[v]) {
                long long new_dst = (dist[v] * w) % MOD;
                if (dist[u] > new_dst) {
                    dist[u] = new_dst;
                    pq.emplace(new_dst, u);
                }
            }
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i)
            ret[i] = (int)(dist[i] % MOD);

        return ret;
    }
};
