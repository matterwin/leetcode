class Solution(object):
    def numIslands(self, grid):
        m, n = len(grid), len(grid[0])
        isles = 0

        self.dr = [-1, 1, 0, 0]
        self.dc = [0, 0, -1, 1]

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    isles += 1
                    self.dfs(i, j, m, n, grid)

        return isles

    def dfs(self, i, j, m, n, grid):
        if i < 0 or j < 0 or i == m or j == n:
            return
        if grid[i][j] == '0':
            return

        grid[i][j] = '0'

        for k in range(4):
            self.dfs(i + self.dr[k], j + self.dc[k], m, n, grid)
