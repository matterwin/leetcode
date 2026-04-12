class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ret = [] 
        for i in range(numRows):
            _ = [1] * (i + 1)
            ret.append(_)

        for i in range(2, numRows):
            for j in range(1, i):
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j]

        return ret
