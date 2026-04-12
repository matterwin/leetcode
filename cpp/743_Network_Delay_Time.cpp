class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);        
        dist[k] = 0;

        std::priority_queue<
            pair<int, int>,             // {distance, node} from src
            vector<pair<int, int>>,
            greater<>> 
        mnh;

        mnh.push({0, k});

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& con : times)
           adj[con[0]].push_back({con[1], con[2]});

        while (!mnh.empty())             
        {
            auto [d, u] = mnh.top();
            mnh.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u])
            {
                if (dist[v] > d + w)
                {
                    dist[v] = d + w; 
                    mnh.push({dist[v], v});
                }
            }
        }

        int ret = 0;
        for (int d : dist)
        {
            if (d == INT_MAX) return -1;
            ret = max(ret, dist[i]);
        }

        return ret;
    }
};

