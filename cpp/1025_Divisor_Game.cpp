const int N = 10000;
int dp[N][N];

int solve(int n, int k, int f = 1) { 
     if (n == 0 || k == 0)
         return dp[n][k] = f;
    
     if (dp[n][k] != -1)
         return dp[n][k];
     
     if (n % k ==0 ) f = solve(n- kx , k, 1^f);
     else f = solve( n , k-1 , f);
     
    return dp[n][k] = f;
}

class Solution {
public:
    bool divisorGame(int n) {
        if (n == 1) return false;
        if (n == 2) return true;
        
        memset(dp , -1, sizeof(dp));
        if (solve(n, n - 1, 1)) return true;
        return false;
    }
};
