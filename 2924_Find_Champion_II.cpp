class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegs(n, 0);
        for (auto e : edges)
            indegs[e[1]]++;

        int champ = -1;
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            if (indegs[i] == 0)
            {
                cnt++;
                champ = i;
            }
        }

        return cnt > 1 ? -1 : champ;
    }
};


