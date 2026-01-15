class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long sum = 0;
        long long ans = INT_MIN;
        int mini = INT_MAX;
        
        for(int it : nums)
            sum += it;
        
        for(int i = nums.size()-1; i > 0; i--){
            sum -= nums[i];
            mini = min(mini, nums[i]);

            ans = max(ans, sum - mini);
        }
        return ans;
    }
};