class Solution {
public:
    int find(int p, vector<int>& parent)
    {
        if (p == parent[p]) return p;
        return parent[p] = find(parent[p], parent);
    }
    bool unite(int u, int v, vector<int>& parent)
    {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu == pv)
            return true;
        parent[pv] = pu;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();           

        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;

        vector<int> ret(2, -1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (unite(u, v, parent);
            { 
                ret[0] = u;
                ret[1] = v;
            }
        }

        return ret;
    }
};

