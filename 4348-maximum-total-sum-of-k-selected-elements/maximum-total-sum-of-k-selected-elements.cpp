class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long total = 0;

        int i = n-1;

        while(k--){
            if(mul > 0){
                total += 1LL * nums[i]*mul;
            }else{
                total += nums[i];
            }

            i -= 1;
            mul -= 1;
        }

        return total;
    }
};