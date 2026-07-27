//self approach using 2-pointers
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> mpp;
        int sum = 0;

        int i = 0, j = 0;
        while(i <= j && j < n){
            mpp[nums[j]] += 1;;
            sum += nums[j];

            if(mpp[nums[j]] > 1){
                while(i < j && mpp[nums[j]] > 1){
                    mpp[nums[i]] -= 1;
                    sum -= nums[i];
                    i += 1;
                }
            }
            ans = max(ans, sum);
            j += 1;
        }

        return ans;
    }
};