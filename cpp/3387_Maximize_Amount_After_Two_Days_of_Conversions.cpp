class Solution 
{
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2)
    {
        unordered_map<string, vector<pair<string, double>>> adj1, adj2;
        for (int i = 0; i < pairs1.size(); ++i)
        {
            string a = pairs1[i][0];
            string b = pairs1[i][1];
            double r = rates1[i];

            adj1[a].push_back({b, r});
            adj1[b].push_back({a, 1.0 / r});
        }

        for (int i = 0; i < pairs2.size(); ++i) 
        {
            string a = pairs2[i][0];
            string b = pairs2[i][1];
            double r = rates2[i];

            adj2[a].push_back({b, r});
            adj2[b].push_back({a, 1.0 / r});
        }

        unordered_map<string, double> best1;
        best1[initialCurrency] = 1.0;
        queue<string> q;
        q.push(initialCurrency);

        while (!q.empty()) 
        {
            string cur = q.front(); q.pop();
            double curVal = best1[cur];

            for (auto [next, rate] : adj1[cur]) 
            {
                double nextVal = curVal * rate;
                if (nextVal > best1[next])
                {
                    best1[next] = nextVal;
                    q.push(next);
                }
            }
        }

        unordered_map<string, vector<pair<string,double>>> revAdj2;
        for (auto &[from, neighbors] : adj2) 
            for (auto &[to, rate] : neighbors)
                revAdj2[to].push_back({from, rate});

        unordered_map<string, double> best2;
        best2[initialCurrency] = 1.0;
        q.push(initialCurrency);

        while (!q.empty()) 
        {
            string cur = q.front(); q.pop();
            double curVal = best2[cur];

            for (auto [next, rate] : revAdj2[cur]) 
            {
                double nextVal = curVal * rate;
                if (nextVal > best2[next]) 
                {
                    best2[next] = nextVal;
                    q.push(next);
                }
            }
        }

        double answer = 0.0;
        for (auto &[currency, val1] : best1) 
            if (best2.count(currency))
                answer = max(answer, val1 * best2[currency]);

        return answer;
    }
};
