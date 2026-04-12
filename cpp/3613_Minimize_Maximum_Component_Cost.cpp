#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int minCost(int n, vector<vector<int>>& edges, int k) 
    {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        auto find = [&](int x, auto &&self) -> int 
        {
            return parent[x] == x ? x : parent[x] = self(parent[x], self);
        };

        auto unite = [&](int x, int y) -> bool 
        {
            int px = find(x, find), py = find(y, find);
            if (px == py) return false;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else { parent[py] = px; rank[px]++; }
            return true;
        };

        vector<int> mst_edges;

        for (auto &e : edges) 
        {
            int u = e[0], v = e[1], w = e[2];
            if (unite(u, v)) mst_edges.push_back(w);
        }

        sort(mst_edges.rbegin(), mst_edges.rend());
        mst_edges.erase(mst_edges.begin(), mst_edges.begin() + (k - 1));

        return mst_edges.empty() ? 0 : mst_edges[0];
    }
};


