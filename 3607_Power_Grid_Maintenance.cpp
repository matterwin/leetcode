#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp) return;
        if (xp < yp) parent[yp] = xp;
        else parent[xp] = yp;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<bool> online(c + 1, true); 

        parent.resize(c + 1);
        iota(parent.begin(), parent.end(), 0);

        for (auto con : connections)
            unite(con[0], con[1]);

        unordered_map<int, pair<vector<int>, int>> stations;

        for (int i = 1; i <= c; ++i)
        {
            int pi = find(i);
            if (stations.find(pi) == stations.end())
                stations[pi] = {{}, 0}; 
            stations[pi].first.push_back(i);
        }

        vector<int> ret;
        for (auto q : queries)
        {
            int qty = q[0];
            int x = q[1];

            if (qty == 2)
            {
                online[x] = false;
                continue;
            }

            int r = -1;
            if (online[x])
                r = x;
            else 
            {
                int xp = find(x);
                auto& station_pair = stations[xp];
                auto& station = station_pair.first;
                auto& leader = station_pair.second;

                while (leader < station.size())
                {
                    if (!online[station[leader]])
                        ++leader;
                    else
                        break;
                }

                if (leader != station.size())
                    r = station[leader]; 
            }
            ret.push_back(r);
        }

        return ret;
    }
};

