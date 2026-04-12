class Solution:
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def unite(self, x, y):
        xp = self.find(x)
        yp = self.find(y)
        if xp == yp:
            return
        self.parent[yp] = xp
    
    def numberOfComponents(self, properties, k: int) -> int:
        n = len(properties)
        
        self.parent = list(range(n))
        
        freqs = [set(props) for props in properties]
        
        for i in range(n):
            for j in range(i+1, n):
                common = len(freqs[i] & freqs[j])
                if common >= k:
                    self.unite(i, j)
        
        components = set(self.find(i) for i in range(n))
        return len(components)
