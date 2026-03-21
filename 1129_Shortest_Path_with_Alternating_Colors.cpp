class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        enum { RED = 0, BLUE = 1 };
        vector<int> ans(n, -1);       
        ans[0] = 0;

        vector<vector<int>> blue_adj(n), red_adj(n);
        for (auto& e : redEdges ) red_adj[e[0]].push_back(e[1]);
        for (auto& e : blueEdges) blue_adj[e[0]].push_back(e[1]);

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[0][RED] = dist[0][BLUE] = 0;

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][RED] = true;
        visited[0][BLUE] = true;

        queue<pair<int, int>> q;
        q.push({0, RED});
        q.push({0, BLUE});

        while (!q.empty())
        {
            auto p = q.front(); 
            q.pop();

            int u = p.first;
            int prev_color = p.second;

            if (prev_color == BLUE)
            {
                for (auto& next : red_adj[u])
                {
                    if (visited[next][RED]) continue;

                    visited[next][RED] = true;
                    dist[next][RED] = dist[u][BLUE] + 1;
                    q.push({next, RED});
                }
            }
            else
            {
                for (auto& next : blue_adj[u])
                {
                    if (visited[next][BLUE]) continue;

                    visited[next][BLUE] = true;
                    dist[next][BLUE] = dist[u][RED] + 1;
                    q.push({next, BLUE});
                }
            }
        }

        for (int i = 0; i < n; ++i) 
        {
            int d = min(dist[i][RED], dist[i][BLUE]);
            if (d != INT_MAX)
                ans[i] = d;
        }

        return ans;
    }
};

