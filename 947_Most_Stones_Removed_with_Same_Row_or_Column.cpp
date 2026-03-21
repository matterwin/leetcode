class DSU 
{
public:
    unordered_map<int, int> parent;

    int find(int x) 
    {
        if (!parent.count(x)) parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) 
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[py] = px;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        int OFFSET = 10001;

        for (auto &stone : stones) 
        {
            int row = stone[0];
            int col = stone[1] + OFFSET;
            dsu.unite(row, col);
        }

        unordered_set<int> components;
        for (auto &stone : stones)
            components.insert(dsu.find(stone[0]));

        return stones.size() - components.size();
    }
};

