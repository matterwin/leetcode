#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dpHelper(int i, int j, string& w1, string& w2, vector<vector<int>>& memo) {
        if (i == w1.size()) return w2.size() - j;
        if (j == w2.size()) return w1.size() - i;

        if (memo[i][j] != -1) return memo[i][j];

        if (w1[i] == w2[j])
            return memo[i][j] = dpHelper(i + 1, j + 1, w1, w2, memo);

        int insertOp  = 1 + dpHelper(i, j + 1, w1, w2, memo);
        int deleteOp  = 1 + dpHelper(i + 1, j, w1, w2, memo);
        int replaceOp = 1 + dpHelper(i + 1, j + 1, w1, w2, memo);

        return memo[i][j] = min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string w1, string w2) {
        vector<vector<int>> memo(w1.size(), vector<int>(w2.size(), -1));
        return dpHelper(0, 0, w1, w2, memo);
    }
};
