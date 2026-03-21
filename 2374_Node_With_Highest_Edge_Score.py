class Solution(object):
    def edgeScore(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        
        n = len(edges)
        weights = [0] * n

        for i in range(0, n):
            weights[edges[i]] += i

        mxw = float('-inf')
        ret = -1

        for i in range(0, n):
            if (weights[i] > mxw):
                mxw = weights[i]
                ret = i

        return ret
