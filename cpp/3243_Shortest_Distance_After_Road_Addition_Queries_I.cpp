class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
            adj[i].push_back(i + 1);

        vector<int> ans;
        
        auto bfs = [&](int start) 
        {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            while (!q.empty()) 
            {
                int u = q.front(); q.pop();
                if (u == n - 1) return dist[u];
                for (int nxt : adj[u]) 
                {
                    if (dist[nxt] == -1) 
                    {
                        dist[nxt] = dist[u] + 1;
                        q.push(nxt);
                    }
                }
            }
            return dist[n - 1];
        };
        
        for (auto &q : queries) 
        {
            adj[q[0]].push_back(q[1]);
            ans.push_back(bfs(0));
        }
        
        return ans;
    }
};
