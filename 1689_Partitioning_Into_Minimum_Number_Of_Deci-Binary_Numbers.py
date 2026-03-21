class Solution(object):
    def minPartitions(self, n):
        """
        :type n: str
        :rtype: int
        """
        return max(int(c) for c in n)
