from heapq import heappush, heappop

class Solution(object):
    def minTimeToReach(self, moveTime):
        n, m = len(moveTime), len(moveTime[0])

        dist = [[float('inf')] * m for _ in range(n)]
        dist[0][0] = 0

        pq = []
        heappush(pq, (0, 0, 0))

        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        while pq:
            time, r, c = heappop(pq)

            if time > dist[r][c]:
                continue

            if r == n - 1 and c == m - 1:
                return time

            for k in range(4):
                nr, nc = r + dr[k], c + dc[k]
                if 0 <= nr < n and 0 <= nc < m:
                    newTime = max(moveTime[nr][nc], time) + 1
                    if newTime < dist[nr][nc]:
                        dist[nr][nc] = newTime
                        heappush(pq, (newTime, nr, nc))

        return -1
