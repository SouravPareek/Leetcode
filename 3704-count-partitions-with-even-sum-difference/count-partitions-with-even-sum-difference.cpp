//self
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int it : nums)
            sum += it;
        
        int cnt = 0;
        int temp_sum = 0;

        for(int i = 0; i < nums.size()-1; i++){
                temp_sum += nums[i];

            if(abs((sum-temp_sum)-(temp_sum)) % 2 == 0)
                cnt += 1;
        }
        return cnt;
    }
};