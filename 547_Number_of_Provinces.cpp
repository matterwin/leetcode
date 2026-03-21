class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int cur_node, vector<bool>& seen, int node_cnt)
    {
        if (seen[cur_node]) return;

        seen[cur_node] = true;

        for (int node = 0; node < node_cnt; ++node)
        {
            int has_edge = isConnected[cur_node][node];
            if (has_edge && !seen[node])
                dfs(isConnected, node, seen, node_cnt);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int node_cnt = isConnected.size();       
        int islands = 0;

        vector<bool> seen(node_cnt, false);
        for (int node = 0; node < node_cnt; ++node)
        {
            if (!seen[node])
            {
                ++islands;
                dfs(isConnected, node, seen, node_cnt);
            }
        }

        return islands;
    }
};

[1,0,0]
[0,1,0]
[0,0,1]
