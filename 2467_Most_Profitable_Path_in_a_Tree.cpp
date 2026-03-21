class Solution {
public:
    void dfs_alice(int cur, int parent, vector<vector<int>>& adj, int time, int cur_income, int& best_income, 
            vector<int>& amount, vector<int>& bobs_visited_time, vector<bool>& bobs_path)
    {
        if (bobs_path[cur])
        {
            if (bobs_visited_time[cur] == time) cur_income += (amount[cur] / 2); // tie
            else if (bobs_visited_time[cur] > time) cur_income += amount[cur];    // Alice arrives first
            // else Bob already came -> 0 profit, do nothing
        }
        else 
            cur_income += amount[cur];

        bool is_leaf = true;
        for (auto next : adj[cur])
        {
            if (next == parent) continue; // avoid going back
            is_leaf = false;
            dfs_alice(next, cur, adj, time + 1, cur_income, best_income, amount, bobs_visited_time, bobs_path);
        }

        if (is_leaf)
            best_income = max(best_income, cur_income);
    }

    bool dfs_bob(int cur, int parent, vector<vector<int>>& adj, vector<int>& bobs_visited_time, int time, vector<bool>& path)
    {
        bobs_visited_time[cur] = time;

        if (cur == 0)
        {
            path[cur] = true;
            return true;
        }

        for (auto next : adj[cur])
        {
            if (next == parent) continue;
            if (dfs_bob(next, cur, adj, bobs_visited_time, time + 1, path))
            {
                path[cur] = true;
                return true;
            }
        }

        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> bobs_visited_time(n, -1);
        vector<bool> bobs_path(n, false);

        dfs_bob(bob, -1, adj, bobs_visited_time, 0, bobs_path);

        int best_income = INT_MIN;
        dfs_alice(0, -1, adj, 0, 0, best_income, amount, bobs_visited_time, bobs_path);

        return best_income;
    }
};
