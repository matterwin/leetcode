class Solution(object):
    def findChampion(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        indegs = [0] * n 
        for edge in edges:
            indegs[edge[1]] += 1

        champ = -1 
        cnt = 0

        for i in range(0, n):
            if indegs[i] == 0:
                champ = i
                cnt += 1

        return -1 if cnt > 1 else champ
