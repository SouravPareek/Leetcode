class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();

        int gcd_n = nums[0];

        for(int i = 1; i < n; i++){
            gcd_n = gcd(gcd_n, nums[i]);
            if(gcd_n == 1)
                return true;
        }
        if(gcd_n == 1)
            return true;
            
        return false;
        
    }
};