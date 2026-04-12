class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        n = len(edges)
        parent = [i for i in range(n + 1)]

        ret = [-1, -1]

        for edge in edges:
            u, v = edge[0], edge[1]
            if self.unite(u, v, parent):
                ret = [u, v]

        return ret

    def find(self, v, parent):
        if v == parent[v]:
            return v
        parent[v] = self.find(parent[v], parent)
        return parent[v]

    def unite(self, u, v, parent):
        pu = self.find(u, parent)
        pv = self.find(v, parent)

        if pu == pv:
            return True

        parent[pu] = pv
        return False



