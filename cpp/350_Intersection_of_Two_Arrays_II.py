class Solution:
    def intersect(self, n1: List[int], n2: List[int]) -> List[int]:
        freq = [0] * 1001

        for n in n1:
            freq[n] += 1

        ret = []

        for n in n2:
            if freq[n] > 0:
                ret.append(n)
                freq[n] -= 1

        return ret

