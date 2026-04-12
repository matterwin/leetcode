class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<int> indeg(n, 0);
        vector<string> ret;
        unordered_map<string, vector<int>> mp; // item, recipe index (ri)

        for (int i = 0; i < n; i++)
        {
            for (auto ingredient : ingredients[i]) 
            {
                indeg[i]++;
                mp[ingredient].push_back(i); 
            }
        }

        queue<string> q;
        // all supplies have indeg 0 by default
        for (auto &supply : supplies) 
            q.push(supply);

        while (!q.empty())
        {
            auto t = q.front(); 
            q.pop();

            for (int ri : mp[t])
            {
                indeg[ri]--;
                if (indeg[ri] == 0)
                {
                    ret.push_back(recipes[ri]);
                    q.push(recipes[ri]);
                }
            }
        }

        return ret;
    }
};
