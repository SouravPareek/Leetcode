//top down
class Solution {
private:
    int minCost(vector<int>& cost, vector<int>& dp, int n){
        if(n < 0)
            return 0;
        if(n == 0 || n== 1)
            return cost[n];
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = cost[n] + min(minCost(cost, dp, n-1), minCost(cost, dp, n-2));

        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1, -1);

        return dp[n] = min(minCost(cost, dp, n-1), minCost(cost, dp, n-2));
    }
};