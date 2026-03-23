class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(auto &it : nums)
            it = abs(it);
        
        sort(nums.begin(), nums.end());

        long long subtr = 0;
        long long add = 0;

        for(int i = 0; i < n/2; i++)
            subtr += nums[i]*nums[i];
        for(int i = n/2; i < n; i++)
            add += nums[i]*nums[i];

        return add - subtr;
    }
};