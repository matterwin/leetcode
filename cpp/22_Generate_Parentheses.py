class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        s = [''] * (2 * n)

        def gen(open, close, i):
            if open < 0 or close < 0 or close < open:
                return

            if open == 0 and close == 0:
                res.append(''.join(s))
                return

            s[i] = '('
            gen(open - 1, close, i + 1)

            s[i] = ')'
            gen(open, close - 1, i + 1)

        gen(n, n, 0)
        return res
