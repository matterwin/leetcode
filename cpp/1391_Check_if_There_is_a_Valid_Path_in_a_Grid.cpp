#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> dirs = 
    {
        {{0,-1}, {0,1}},   // street 1: left <-> right
        {{-1,0}, {1,0}},   // street 2: up <-> down
        {{0,-1}, {1,0}},   // street 3: left <-> down
        {{0,1}, {1,0}},    // street 4: right <-> down
        {{0,-1}, {-1,0}},  // street 5: left <-> up
        {{0,1}, {-1,0}}    // street 6: right <-> up
    };

    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;

        while (!q.empty()) 
        {
            auto [x, y] = q.front(); q.pop();
            int num = grid[x][y] - 1;

            for (auto dir : dirs[num]) 
            {
                int nx = x + dir.first, ny = y + dir.second;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) 
                    continue;

                int neighbor_num = grid[nx][ny] - 1;
                for (auto back_dir : dirs[neighbor_num]) 
                {
                    if (nx + back_dir.first == x && ny + back_dir.second == y) 
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        break;
                    }
                }
            }
        }

        return visited[m-1][n-1];
    }
};
