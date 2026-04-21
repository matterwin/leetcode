// bottom up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n + 1, 0);

		dp[0] = cost[0];
		dp[1] = cost[1];

		for (int i = 2; i < n; ++i)
			dp[i] = min(dp[i - 1],  dp[i - 2]) + cost[i];

		return min(dp[n - 1], dp[n - 2]);
    }
};

// O(1) space 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int c = min(a, b) + cost[i];
            a = b;
            b = c;
        }

        return min(a, b);
    }
};
