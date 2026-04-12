#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& vids, vector<vector<int>>& friends, int id, int the_level)
    {
        int n = friends.size();
        vector<vector<int>> adj(n);
        for (int i = 0 ; i < n; ++i)
            for (auto& f : friends[i])
                adj[i].push_back(f);

        queue<int> q;
        q.push(id);

        unordered_map<string, int> mp;
        vector<bool> visited(n, false);

        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int node = q.front(); q.pop();
                if (visited[node]) continue;
                visited[node] = true;

                if (level == the_level)
                {
                    for (auto &vid : vids[node])
                        mp[vid]++;
                }

                for (int next : adj[node])
                {
                    if (!visited[next])
                        q.push(next);
                }
            }
            ++level;
        }

        vector<pair<int, string>> freq;
        for (auto &[vid, cnt] : mp)
            freq.push_back({cnt, vid});

        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto &[cnt, vid] : freq)
            ans.push_back(vid);

        return ans;
    }
};

