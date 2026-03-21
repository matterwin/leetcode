#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0 || i == m || j == n) return 0;
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        int cnt = 1;
        for (int k = 0; k < 4; ++k)
            cnt += dfs(dr[k] + i, dc[k] + j, m, n, grid);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, m, n, grid));
        
        return ans;
    }
};
