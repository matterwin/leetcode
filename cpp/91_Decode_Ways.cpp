#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int i, string &s, vector<int> &memo) {
        if (i == s.size()) return 1;

        if (s[i] == '0') return 0;

        if (memo[i] != -1) return memo[i];

        int ways = dfs(i + 1, s, memo);

        if (i + 1 < s.size() &&
            (s[i] == '1' ||
            (s[i] == '2' && s[i + 1] <= '6')))
        {
            ways += dfs(i + 2, s, memo);
        }

        return memo[i] = ways;
    }

    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(0, s, memo);
    }
};
