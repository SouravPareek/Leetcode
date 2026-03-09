class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0;
        for(int it : nums)
            sum += it;
        
        long long prod = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            sum -= nums[i];

            if(sum == prod)
                return i;
            if(sum < prod)
                break;

            prod *= nums[i];
        }
        return -1;
    }
};