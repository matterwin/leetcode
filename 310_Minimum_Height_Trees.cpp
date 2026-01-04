class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> deg(n);

        for (auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1) q.push(i);

        int remain = n;
        while (remain > 2)
        {
            int sz = q.size();
            remain -= sz;
            while (sz--)
            {
                int leaf = q.front(); q.pop();
                for (int neighbor : adj[leaf])
                {
                    // getting rid of leaves layer by layer
                    deg[neighbor]--;
                    if (deg[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
          
        vector<int> ret;
        while (!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};



