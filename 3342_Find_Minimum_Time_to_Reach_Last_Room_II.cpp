class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<
            tuple<int, int, int, int>,
            vector<tuple<int, int, int, int>>,
            greater<tuple<int, int, int, int>>
        > pq;

        pq.push({0, 0, 0, 0});

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!pq.empty()) 
        {
            auto [time, r, c, alt] = pq.top();
            pq.pop();

            if (time > dist[r][c]) continue;

            if (r == n - 1 && c == m - 1) 
                return time;

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) 
                {
                    int add_time = alt & 1;
                    int newTime = max(moveTime[nr][nc], time) + 1 + add_time;

                    if (newTime < dist[nr][nc]) 
                    {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, nr, nc, alt ^ 1});
                    }
                }
            }
        }

        return -1;
    }
};
