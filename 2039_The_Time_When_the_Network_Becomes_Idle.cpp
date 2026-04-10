class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        int maxTime = 0;

        for (int i = 1; i < n; i++) {
            int roundTrip = 2 * dist[i];

            int lastSend = 0;
            if (roundTrip > patience[i])
                lastSend = ((roundTrip - 1) / patience[i]) * patience[i];

            int finalTime = lastSend + roundTrip;
            maxTime = max(maxTime, finalTime);
        }

        return maxTime + 1;
    }
};
