class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp) return;

        if (rank[xp] < rank[yp]) parent[xp] = yp;
        else if (rank[xp] > rank[yp]) parent[yp] = xp;
        else { parent[yp] = xp; rank[xp]++; }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);

        for (auto &e : edges) unite(e[0], e[1]);

        unordered_map<int, int> components;
        for (int i = 0; i < n; ++i)
            components[find(i)]++;

        long long ret = 0;
        long long remaining = n;

        for (auto &[_, size] : components) {
            ret += size * (remaining - size);
            remaining -= size;
        }

        return ret;
    }
};
