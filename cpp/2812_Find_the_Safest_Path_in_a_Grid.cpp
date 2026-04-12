class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // get all positions of thieves
        vector<pair<int, int>> pos_t;
        int n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    pos_t.push_back({i, j});

        vector<vector<int>> pos_from_t(n, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < pos_t.size(); ++i)
        {
            int x = pos_t[i].first, y = pos_t[i].second;
            q.push({x, y});
            pos_from_t[x][y] = 0;
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx == n || ny == n) continue;
                // first thief is the closest and decides the position;
                // all others are too slow, so they continue.
                if (pos_from_t[nx][ny] != -1) continue;

                pos_from_t[nx][ny] = pos_from_t[x][y] + 1;
                q.push({nx, ny});
            }
        }

        // (safety, x, y)
        priority_queue<tuple<int, int, int>> pq;
        pq.push({pos_from_t[0][0], 0, 0});

        vector<vector<int>> best(n, vector<int>(n, -1));
        best[0][0] = pos_from_t[0][0];

        while (!q.empty()) 
        {
            auto [safety, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1) 
                return safety;

            for (int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx == n || ny == n) continue;

                int path_safety = min(safety, pos_from_t[nx][n]y);

                if (path_safety > best[nx][ny])
                {
                    best[nx][ny] = path_safety;
                    pq.push({path_safety, nx, ny});
                }
            }
        }
    }
};
