class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, pair<int, int>>>> adj(n);

        for (auto& e : edges)
            adj[e[0]].push_back({e[1], {e[2], e[3]}});

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) 
        {
            auto [time, node] = pq.top();
            pq.pop();

            if (node == n - 1) return time;
            if (time > dist[node]) continue;

            for (auto& [neigh, range] : adj[node])
            {
                if (time > range.second)
                    continue;

                int curr_time = max(time, range.first);

                if (dist[neigh] > curr_time + 1) 
                {
                    dist[neigh] = curr_time + 1;
                    pq.push({curr_time + 1, neigh});
                }
            }
        }

        return -1;
    }
};

