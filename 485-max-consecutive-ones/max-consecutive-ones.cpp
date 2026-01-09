class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int ans = 0;

        for(int it : nums){
            if(it == 1){
                curr += 1;
                ans = max(ans, curr);
            }else{
                curr = 0;
            }
        }
        return ans;
    }
};