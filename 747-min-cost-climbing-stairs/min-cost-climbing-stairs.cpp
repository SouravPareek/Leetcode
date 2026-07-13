//space optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(3, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++){
            dp[2] = cost[i] + min(dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return min(dp[0], dp[1]);
    }
};