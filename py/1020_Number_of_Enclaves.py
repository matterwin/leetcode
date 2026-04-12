class Solution:
    def numEnclaves(self, grid):
        m, n = len(grid), len(grid[0])
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        def dfs(i, j):
            if i < 0 or j < 0 or i >= m or j >= n:
                return 0, False
            if grid[i][j] == 0:
                return 0, True

            enclosed = True
            if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                enclosed = False

            grid[i][j] = 0
            size = 1

            for k in range(4):
                s, e = dfs(i + dx[k], j + dy[k])
                size += s
                enclosed = enclosed and e

            return size, enclosed

        total_cells = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    size, is_enclosed = dfs(i, j)
                    if is_enclosed:
                        total_cells += size

        return total_cells
