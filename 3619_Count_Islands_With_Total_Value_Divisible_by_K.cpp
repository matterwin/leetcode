class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int k)
    {
        if (i < 0 || j < 0 || i == m || j == n) return 0;
        if (grid[i][j] == 0) return 0;

        int val = grid[i][j] % k;
        grid[i][j] = 0;

        for (int d = 0; d < 4; ++d)
        {
            // (a + b) % k -> ((a % k) + (b % k)) % k
            val = (val + dfs(i + dx[d], j + dy[d], m, n, grid, k)) % k;
        }
        return val;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] > 0)
                {
                    int tot_mod = dfs(i, j, m, n, grid, k);
                    if (tot_mod == 0)
                        ++ans;
                }   
            }
        }
        return ans;
    }
};
