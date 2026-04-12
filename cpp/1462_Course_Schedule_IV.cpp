class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<bool> ans(sz, false); 
        vector<vector<int>> adj(numCourses);

        queue<int> q;
        vector<int> indeg(numCourses, 0);
        for (auto prereq : prerequisites)
        {
            adj[prereq[0]].push_back(prereq[1]);
            indeg[prereq[1]]++;
        }

        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        while (!q.empty())
        {
            int top = q.front(); q.pop();
            for (int next : adj[top])
            {
                reachable[top][next] = true;
                // propagate ts
                for (int i = 0; i < numCourses; i++)
                    if (reachable[i][top])
                        reachable[i][next] = true;
                indeg[next]--;
                if (indeg[next] == 0) q.push(next);
            }
        }

        for (int i = 0; i < sz; ++i)
        {
            vector<int> query = queries[i];
            ans[i] = reachable[query[0]][query[1]];
        }

        return ans;
    }
};

