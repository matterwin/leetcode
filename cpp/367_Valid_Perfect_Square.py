class Solution:
    def isPerfectSquare(self, x: int) -> bool:
        if x < 2:
            return True

        l, r = 1, x

        while l <= r:
            mid = l + (r - l) // 2
            sq = mid * mid

            if sq == x:
                return True
            elif sq < x:
                l = mid + 1
            else:
                r = mid - 1

        return False

