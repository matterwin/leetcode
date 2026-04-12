class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return climbStairs(n, memo);
    }
    int climbStairs(int n, vector<int>& memo) {
        if (n == 0 || n == 1) return 1;
        if (memo[n] != -1) return memo[n];

        int result = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        memo[n] = result;
        return result;
    }
};

