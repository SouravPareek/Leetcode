//top down (self)
class Solution {
private:
    int helper(int house, vector<int>& nums, vector<int>& dp){
        if(house >= nums.size())
            return 0;
        
        if(dp[house] != -1)
            return dp[house];
        
        return dp[house] = nums[house] + max(helper(house+2, nums, dp), helper(house+3, nums, dp));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        if(n == 1)
            return nums[0];

        vector<int> dp(n+1, -1);

        return dp[n] = max(helper(0, nums, dp), helper(1, nums, dp));
    }
};