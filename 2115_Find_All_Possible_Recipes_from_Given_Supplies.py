from collections import deque, defaultdict 
from typing import List

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        n = len(recipes)
        indeg = [0] * n
        ret = [] 

        mp = defaultdict(list) 

        for i in range(n):
            for ingredient in ingredients[i]:
                indeg[i] += 1
                mp[ingredient].append(i)

        q = deque(supplies) 

        while q: 
            t = q.popleft() 

            for ri in mp[t]: 
                indeg[ri] -= 1
                if indeg[ri] == 0:
                    ret.append(recipes[ri])
                    q.append(recipes[ri])
        return ret
