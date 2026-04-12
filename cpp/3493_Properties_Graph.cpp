class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp) return;
        parent[yp] = xp;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<bitset<101>> freqs(n);  
             
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int p : properties[i])
                freqs[i][p] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int common = (freqs[i] & freqs[j]).count();
                if (common >= k)
                    unite(i, j);
            }
        }

        unordered_set<int> components;
        for (int i = 0; i < n; ++i)
            components.insert(find(i));
        return components.size();
    }
};

