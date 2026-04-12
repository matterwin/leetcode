class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int m = grid.size(), m = grid[0].size(), c = 0;
        vector<int> inRow(m, 0);
        vector<int> inCol(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                {
                    ++c;
                    ++inRow[i];
                    ++inCol[j];
                }
            }
        }
      
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && inRow[i] <= 1 && inCol[j] <= 1) 
                    c--;
            }
        }

       return c;
    }
};
