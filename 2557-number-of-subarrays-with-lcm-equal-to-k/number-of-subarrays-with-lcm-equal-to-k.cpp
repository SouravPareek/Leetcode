//bit optimized
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int lcm_n = 1;
            for(int j = i; j < n; j++){
                if(k%nums[j] != 0)
                    break;
                
                lcm_n = lcm(lcm_n, nums[j]);

                if(lcm_n == k)
                    cnt += 1;
                else if(lcm_n > k)
                    break;
            }
        }
        return cnt;
    }
};