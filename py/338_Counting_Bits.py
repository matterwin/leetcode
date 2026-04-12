class Solution:
    def countBits(self, n: int) -> List[int]:
        ret[] = [0 * n]
        for i in range(1, n + 1):
            ret[i] = ret[i >> 1] + (i & 1)
        return ret
