#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int minCost(int n, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto e : edges) 
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int src = 0;
        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) 
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (u == n - 1)
                return dist[u];

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) 
            {
                if (dist[u] + w < dist[v]) 
                {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[n - 1] == INT_MAX ? - 1 : dist[n - 1];
    }
};

