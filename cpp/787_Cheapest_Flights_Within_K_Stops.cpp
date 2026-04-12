class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                        int src, int dst, int k)
    {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) 
        {
            vector<int> tmp = dist;
            for (auto& f : flights) 
            {
                if (dist[f[0]] == INF) continue;
                tmp[f[1]] = min(tmp[f[1]], dist[f[0]] + f[2]);
            }
            dist = tmp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};


