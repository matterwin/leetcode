from collections import deque

class Solution(object):
    def shortestDistanceAfterQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        adj = [[] for _ in range(n)]

        for i in range(n - 1):
            adj[i].append(i + 1)

        def bfs():
            dist = [-1] * n
            q = deque([0])
            dist[0] = 0 

            while q:
                u = q.popleft()
                if u == n - 1:
                    return dist[u]

                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)

            return dist[n - 1]

        ans = []

        for u, v in queries:
            adj[u].append(v)
            ans.append(bfs())

        return ans
        
