class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        int maxi = nums[0];
        int mini = nums[0];

        for(int it : nums){
            maxi = max(maxi, it);
            mini = min(mini, it);
        }

        for(int it : nums){
            if(it > mini && it < maxi)
                cnt += 1;
        }
        return cnt;
    }
};