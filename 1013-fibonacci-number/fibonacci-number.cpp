//self dp solution
class Solution {
private:
    int helper(vector<int>& dp, int n){
        if(n <= 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = helper(dp, n-1) + helper(dp, n-2);;
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);

        return helper(dp, n);
    }
};