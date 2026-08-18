class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == k)
            return *max_element(nums.begin(), nums.end());
        
        vector<int> cnt(51, 0);
        for(int x : nums)
            cnt[x] += 1;
        
        if(k == 1){
            for(int i = 50; i >= 0; i--){
                if(cnt[i] == 1)
                    return i;
            }
            return -1;
        }

        int ans = -1;
        if(cnt[nums[0]] == 1)
            ans = max(ans, nums[0]);
        
        if(cnt[nums.back()] == 1)
            ans = max(ans, nums.back());
        
        return ans;
    }
};