class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(nums[n-1-i] * i > sum)
                cnt += 1;

            sum += nums[n-1-i];
        }
        return cnt;
    }
};