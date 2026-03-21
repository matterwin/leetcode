class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        st = set(nums)
        ret = 0

        for num in st:
            if num - 1 not in st:
                length = 1
                rhs = num + 1
                while rhs in st:
                    length += 1
                    rhs += 1

                ret = max(ret, length)

        return ret
