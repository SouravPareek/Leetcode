class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        int ele;

        for(int it : nums){
            if(cnt == 0){
                ele = it;
                cnt = 1;
                continue;
            }

            if(it != ele){
                cnt -= 1;
            }else{
                cnt += 1;
            }
        }

        return ele;
    }
};