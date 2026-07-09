//top down
class Solution {
private:
    int helper(int n, vector<int>& dp){
        if(n <= 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = helper(n-1, dp) + helper(n-2, dp);

        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);

        dp[n] = helper(n, dp);

        return dp[n];
    }
};