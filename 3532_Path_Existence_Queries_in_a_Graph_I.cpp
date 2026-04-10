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

        if (rank[xp] < rank[yp])
            parent[xp] = yp;
        else {
            parent[yp] = xp;
            if (rank[xp] == rank[yp]) rank[xp]++;
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);

        for (int i = 0; i < n - 1; ++i)
            if (nums[i + 1] - nums[i] <= maxDiff)
                unite(i, i + 1);

        vector<bool> ret;
        for (auto& q : queries)
            ret.push_back(find(q[0]) == find(q[1]));

        return ret;
    }
};
