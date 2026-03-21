#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    int find(int x, vector<int>& parent)
    {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int x, int y, vector<int>& parent)
    {
        int par_x = find(x, parent);
        int par_y = find(y, parent);

        if (par_x == par_y) return;

        parent[par_y] = par_x;
    }

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int edges = connections.size();               
        if (edges < n - 1) return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (auto& edge : connections) unite(edge[0], edge[1], parent);

        unordered_set<int> comps;
        for (int i = 0; i < n; i++) comps.insert(find(i, parent));

        return comps.size() - 1;
    }
};

