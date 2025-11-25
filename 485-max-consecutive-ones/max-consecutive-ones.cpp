//revision
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt1 = 0;
        int current = 0;

        for(int it : nums){
            if(it){
                current += 1;
                cnt1 = max(cnt1, current);
            }else{
                current = 0;
            }
        }

        return cnt1;
    }
};