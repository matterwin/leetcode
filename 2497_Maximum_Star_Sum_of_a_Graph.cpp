class Solution 
{
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) 
    {
        int n = vals.size();
        vector<vector<int>> adj_vals(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj_vals[u].push_back(vals[v]);
            adj_vals[v].push_back(vals[u]);
        }

        int ret = INT_MIN;

        for (int i = 0; i < n; ++i) 
        {
            priority_queue<int, vector<int>, greater<int>> pq;

            for (int val : adj_vals[i])
            {
                if (val <= 0) continue;
                if (pq.size() < k) 
                {
                    pq.push(val);
                } 
                else if (val > pq.top()) 
                {
                    pq.pop();
                    pq.push(val);
                }
            }

            int cur_sum = vals[i];
            while (!pq.empty()) 
            {
                cur_sum += pq.top();
                pq.pop();
            }

            ret = max(ret, cur_sum);
        }

        return ret;
    }
};
