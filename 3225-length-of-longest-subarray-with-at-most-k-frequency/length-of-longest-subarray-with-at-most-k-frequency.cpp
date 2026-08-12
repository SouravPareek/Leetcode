//self
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            mpp[nums[j]] += 1;

            if(mpp[nums[j]] > k){
                while(i < j && mpp[nums[j]] > k){
                    mpp[nums[i]] -= 1;
                    i += 1;
                }
            }
            ans = max(ans, j-i+1);
            j += 1;
        }
        return ans;
    }
};