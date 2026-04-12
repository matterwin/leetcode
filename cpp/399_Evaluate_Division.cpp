class Solution {
public:
    bool dfs(unordered_map<string, vector<pair<string, float>>>& mp, string cur, string end, unordered_set<string>& seen, double prod, double& ans)
    {
        if (seen.find(cur) != seen.end()) return false;
        if (cur == end)
        {
            ans = prod;
            return true;
        }

        bool flag = false;
        seen.insert(cur);
        for (auto pairs : mp[cur])
        {
                string neighbor = pairs.first;
                double weight = pairs.second;
                if (seen.find(neighbor) == seen.end())
                    flag = flag || dfs(mp, neighbor, end, seen, prod * weight, ans);
        }

        return flag;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int qn = queries.size();
        int en = equations.size();
        vector<double> ret(qn, 0.0);

        unordered_map<string, vector<pair<string, float>>> mp;

        for (int i = 0; i < en; ++i)
        {
            vector<string> eq = equations[i];
            double val = values[i];

            mp[eq[0]].push_back({eq[1], val});
            mp[eq[1]].push_back({eq[0], 1 / val});
        }

        for (int i = 0; i < qn; ++i)
        {
            auto query = queries[i];
            string q0 = query[0];
            string q1 = query[1];

            if (mp.find(q0) == mp.end())
            {
                ret[i] = -1.0;
                continue;
            }
            if (mp.find(q1) == mp.end())
            {
                ret[i] = -1.0;
                continue;
            }

            if (q0 == q1)
                ret[i] = 1.0;

            unordered_set<string> seen;
            double ans = 0.0;
            if (!dfs(mp, q0, q1, seen, 1.0, ans))
                ret[i] = -1.0;
            else 
                ret[i] = ans;
        }

        return ret;
    }
};



