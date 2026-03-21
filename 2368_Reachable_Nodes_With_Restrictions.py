class Solution(object):
    def reachableNodes(self, n, edges, r):
        """
        :type n: int
        :type edges: List[List[int]]
        :type restricted: List[int]
        :rtype: int
        """
        
        adj = [[] for _ in range(n)] 
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        restricted = set(r)
        visited = [False] * n 

        def dfs(cur):
            if visited[cur] or cur in restricted:
                return 
            visited[cur] = True 
            for nxt in adj[cur]:
                dfs(nxt) 

        dfs(0)

        return sum(visited)

