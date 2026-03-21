class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, int m, int n) 
    {
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (board[i][j] == 'X' || board[i][j] == 'T') return true;

        bool on_boundary = i == 0 || j == 0 || i == m - 1 || j == n - 1;
        if (on_boundary && board[i][j] == 'O') return false;

        char prev = board[i][j];
        board[i][j] = 'T';

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        bool surrounded = true;
        for (int k = 0; k < 4; ++k) 
        {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (!dfs(nr, nc, board, m, n)) 
                surrounded = false;
        }

        board[i][j] = surrounded ? 'X' : prev;
        return surrounded;
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n = board[0].size();
        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                if (board[i][j] == 'O')
                    dfs(i, j, board, m, n);
    }
};

