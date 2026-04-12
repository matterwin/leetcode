class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1, 0);
        // judge should have n - 1 val in trusts
        for (auto& e : trust)
        {
            trusts[e[0]]--;
            trusts[e[1]]++;
        }

        for (int i = 1; i < n + 1; ++i)
            if (trusts[i] == n - 1)
                return i;

        return -1;
    }
};


