#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& tri) {
		int m = tri.size();

		// fill in as the last row of tri
		vector<int> dp = tri.back();

		// start at 2nd-last row now
		for (int i = m - 2; i >= 0; --i) {
			// stop at i trick since its a triangle
			for (int j = 0; j <= i; ++j) {
				// cost is trivally the cur index value
				// + best path looking down, i.e.
				// dp[i + 1][j] or dp[i + 1][j + 1] in a backwards manner
				dp[j] = tri[i][j] + min(dp[j], dp[j + 1]);
			}
		}

		return dp[0];
	}
};


