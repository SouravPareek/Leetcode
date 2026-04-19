class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = nums[n-1];
        vector<int> hash(n);

        for(int i = n-1; i >= 0; i--){
            mini = min(mini, nums[i]);
            hash[i] = mini;
        }

        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            int score = maxi-hash[i];

            if(score <= k)
                return i;
        }
        return -1;
    }
};