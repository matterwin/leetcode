#include <cstdio>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int* ret, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i == rows || j < 0 || j == cols || grid[i][j] == -1 || grid[i][j] == 0)
            return;

        grid[i][j] = -1;

        if (i+1 >= rows) (*ret)++;
        else if (grid[i+1][j] == 0) (*ret)++;
        else if (grid[i+1][j] == 1) 
            dfs(grid, ret, i+1, j);

        if (j+1 >= cols) (*ret)++;
        else if (grid[i][j+1] == 0) (*ret)++;
        else if (grid[i][j+1] == 1) 
            dfs(grid, ret, i, j+1);

        if (i-1 < 0) (*ret)++;
        else if (grid[i-1][j] == 0) (*ret)++;
        else if (grid[i-1][j] == 1)
            dfs(grid, ret, i-1, j);

        if (j-1 < 0) (*ret)++;
        else if (grid[i][j-1] == 0) (*ret)++;
        else if (grid[i][j-1] == 1)
            dfs(grid, ret, i, j-1);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1)
                    dfs(grid, &ret, i, j);
            }
        }
        return ret;
    }
};

