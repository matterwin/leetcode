class Solution 
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool dfs(int i, int j, int m, int n, int& sz, vector<vector<int>>& grid)
    {
        if (i < 0 || j < 0 || i == m || j == n) return false;
        if (grid[i][j] == 0) return false;

        bool check = true;

        // island is on edge
        if (grid[i][j] == 1 && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) check = false;

        grid[i][j] = 0;

        for (int k = 0; k < 4; ++k)
            if (dfs(i + dx[k], j + dy[k], m, n, grid))
                ++sz;

        return check;
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();        

        int islands = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int sz = 0;
                    if (dfs(i, j, m, n, sz, grid))
                        islands += sz;
                }
            }
        }

        return islands;
    }
};
