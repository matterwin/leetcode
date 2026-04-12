import heapq
from typing import List, Tuple

class Solution:
    def minTime(self, n: int, edges: List[List[int]]) -> int:
        adj: List[List[Tuple[int, Tuple[int,int]]]] = [[] for _ in range(n)]
        for u, v, l, r in edges:
            adj[u].append((v, (l, r)))
        
        dist = [float('inf')] * n
        pq = []
        heapq.heappush(pq, (0, 0))
        dist[0] = 0
        
        while pq:
            time, node = heapq.heappop(pq)
            
            if node == n - 1:
                return time
            if time > dist[node]:
                continue
            
            for neigh, (l, r) in adj[node]:
                if time > r:
                    continue
                
                curr_time = max(time, l)
                
                if dist[neigh] > curr_time + 1:
                    dist[neigh] = curr_time + 1
                    heapq.heappush(pq, (curr_time + 1, neigh))
        
        return -1
