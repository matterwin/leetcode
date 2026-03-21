class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        def dfs(i, j, m, n, grid):
            if i < 0 or j < 0 or i == m or j == n:
                return 0
            if grid[i][j] == 0:
                return 0

            grid[i][j] = 0

            cnt = 1
            for k in range(4):
                cnt += dfs(i + dr[k], j + dc[k], m, n, grid)

            return cnt

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans = max(ans, dfs(i, j, m, n, grid))

        return ans




