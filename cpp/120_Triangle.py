class Solution:
    def minimumTotal(self, tri: List[List[int]]) -> int:
        m = len(tri)

        dp = tri[-1][:]

        for i in range(m - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = tri[i][j] + min(dp[j], dp[j + 1])

        return dp[0]
