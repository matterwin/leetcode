import heapq

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, 2 * w))

        dist = [float('int')] * n
        dist[0] = 0

        pq = [(0, 0)]

        while pq:
            d, u = heapq.heappop(pq)

            if u == n - 1:
                return dist[u]

            if d > dist[u]:
                continue

            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(pq, (dist[v], v))

        return -1 if dist[n - 1] == float('inf') else dist[n - 1]
         
