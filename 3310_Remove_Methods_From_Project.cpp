#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs_rest(int cur, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& touched_by_k)
    {
        if (visited[cur]) return false;
        visited[cur] = true;
        if (touched_by_k[cur])
            return true;

        bool touched_k = false;
        for (int next : adj[cur])
            touched_k = touched_k || dfs_rest(next, adj, visited, touched_by_k);

        if (touched_k)
            touched_by_k[cur] = true;

        return touched_k;
    }
    void dfs_k(int cur, vector<vector<int>>& adj, vector<bool>& touched_by_k)
    {
        if (touched_by_k[cur]) return;
        touched_by_k[cur] = true;

        for (int next : adj[cur])
            dfs_k(next, adj, touched_by_k);
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto invo : invocations)
            adj[invo[0]].push_back(invo[1]);

        int cnt = 0;
        vector<bool> touched_by_k(n, false);
        dfs_k(k, adj, touched_by_k);

        vector<int> ret;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
            if (!visited[i] && !touched_by_k[i])
                dfs_rest(i, adj, visited, touched_by_k);

        for (int i = 0; i < n; ++i)
        {
            cout << i << ": ";
            if (touched_by_k[i])
                cout << "no" << endl;
        }

        return ret;
    }
};


