class Solution {
public:
    void dfs(vector<vector<int>>* image, int i, int j, int color)
    {
        int rows = image.size(), cols = image[0].size();
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size(), cols = image[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (image[i][j] == 1)
                {
                    dfs(image, i, j, color);
                }
            }
        }
        return image; 
    }
};

