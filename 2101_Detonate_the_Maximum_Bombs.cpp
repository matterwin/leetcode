class Solution {
public:
    int dfs(int cur, vector<vector<int>>& adj, vector<bool>& visited) {
        if (visited[cur]) return 0;
        visited[cur] = true;

        int cnt = 1;
        for (auto next : adj[cur])
            cnt += dfs(next, adj, visited);

        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            long long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = xi - bombs[j][0];
                long long dy = yi - bombs[j][1];

                if (dx * dx + dy * dy <= ri * ri)
                    adj[i].push_back(j);
            }
        }

        int max_cnt = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            int cnt = dfs(i, adj, visited);
            max_cnt = max(max_cnt, cnt);
        }

        return max_cnt;
    }
};
