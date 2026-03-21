#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    enum class Dir 
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool has_cycle(char c, int i, int j, Dir dir, int m, int n,
               vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        if (i < 0 || j < 0 || i == m || j == n) return false;
        if (grid[i][j] != c) return false;
        if (visited[i][j]) return true;

        visited[i][j] = 1;

        for (int k = 0; k < 4; ++k)
        {
            Dir ndir = Dir::NONE;
            switch (k)
            {
                case 0: ndir = Dir::UP;    break;
                case 1: ndir = Dir::DOWN;  break;
                case 2: ndir = Dir::LEFT;  break;
                case 3: ndir = Dir::RIGHT; break;
            }

            // prevent going back
            if (dir == Dir::RIGHT && ndir == Dir::LEFT) continue;
            if (dir == Dir::LEFT && ndir == Dir::RIGHT) continue;
            if (dir == Dir::UP && ndir == Dir::DOWN) continue;
            if (dir == Dir::DOWN && ndir == Dir::UP) continue;

            int nx = i + dx[k];
            int ny = j + dy[k];

            if (has_cycle(c, nx, ny, ndir, m, n, grid, visited))
                return true;
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (visited[i][j] == 0)
                    if (has_cycle(grid[i][j], i, j, Dir::NONE, m, n, grid, visited))
                        return true;

        return false;
    }
};

