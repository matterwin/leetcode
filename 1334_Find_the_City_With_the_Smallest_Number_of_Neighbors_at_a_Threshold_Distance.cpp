class Solution {
public:
    vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj, int threshold)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) 
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > threshold) continue;
            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) 
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) 
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int bestCity = -1;
        int minReachable = INT_MAX;

        for (int i = 0; i < n; ++i) 
        {
            vector<int> dist = dijkstra(i, n, adj, distanceThreshold);

            int count = 0;
            for (int j = 0; j < n; ++j)
                if (i != j && dist[j] <= distanceThreshold)
                    count++;

            if (count < minReachable || (count == minReachable && i > bestCity)) 
            {
                minReachable = count;
                bestCity = i;
            }
        }

        return bestCity;
    }
};
