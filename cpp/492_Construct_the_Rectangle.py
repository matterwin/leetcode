class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        r = int(sqrt(area))

        for w in range(r, 0, -1):
            if area % w == 0:
                l = area // w
                return [l, w]
