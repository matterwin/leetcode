class Solution:
    def dfs(self, i, s, memo):
        if i == len(s):
            return 1

        if s[i] == '0':
            return 0

        if memo[i] != -1:
            return memo[i]

        ways = self.dfs(i + 1, s, memo)

        if (
            i + 1 < len(s) and 
            (
                s[i] == '1' or 
                (s[i] == '2' and s[i + 1] <= '6')
            )
        ):
            ways += self.dfs(i + 2, s, memo)
        
        memo[i] = ways
        return ways


    def numDecodings(self, s: str) -> int:
        memo = [-1] * len(s)
        return self.dfs(0, s, memo)
