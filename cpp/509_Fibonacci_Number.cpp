// bottom up
class Solution {
public:
    int fib(int n) {
		if (n <= 1) return n;

		vector<int> dp(n + 1);
		dp[1] = 1;

		for (int i = 2; i <= n; ++i)
			dp[i] = dp[i - 1] + dp[i - 2];

		return dp[n];
    }
};

// top-down 
class Solution {
public:
    int cfib(int n, vector<int>& memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = cfib(n - 1, memo) + cfib(n - 2, memo);
    }
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        return cfib(n, memo);
    }
};

// top-down inline 
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);

        function<int(int)> dfs = [&](int k) {
            if (k <= 1) return k;
            if (memo[k] != -1) return memo[k];
            return memo[k] = dfs(k - 1) + dfs(k - 2);
        };

        return dfs(n);
    }
};
