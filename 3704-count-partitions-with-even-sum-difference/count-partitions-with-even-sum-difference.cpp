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
            if(i == 0)
                temp_sum = 0;
            else
                temp_sum += nums[i-1];

            if(abs((temp_sum)-(sum-temp_sum)) % 2 == 0)
                cnt += 1;
        }
        return cnt;
    }
};