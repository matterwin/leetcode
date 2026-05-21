class Solution:
    def arrangeCoins(self, n: int) -> int:
        l, r, ans = 0, n, 0
        while l <= r:
            mid = l + (r - l) // 2
            coins = mid * (mid + 1) // 2

            if coins <= n:
                ans = mid
                l = mid + 1
            else:
                r = mid - 1

        return ans

