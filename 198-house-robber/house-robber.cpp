//space optimization(self)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
    
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(3, -1);
        dp[0] = nums[0], dp[1] = nums[1], dp[2] = nums[0] + nums[2];

        for(int i = 3; i < n; i++){
            int temp = nums[i] + max(dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = temp;
        }

        return max(dp[0], max(dp[1], dp[2]));
    }
};