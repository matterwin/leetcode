class Solution(object):
    def countIslands(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        m, n = len(grid), len(grid[0])

        ans = 0;

        def dfs(i, j, m, n, grid):
            if i < 0 or j < 0 or i == m or j == n:
                return 0
            if grid[i][j] == 0:
                return 0

            val = grid[i][j] % k
            grid[i][j] = 0

            for k in range(4):
                val = (val + dfs(i + dx[k], j + dy[k], m, n, grid)) % k

            return val

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    tot = dfs(i, j, m, n, grid)
                    if tot % 2 == 0:
                        ans += 1

        return ans
