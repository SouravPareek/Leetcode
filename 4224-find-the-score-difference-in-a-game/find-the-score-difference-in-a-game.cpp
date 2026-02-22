//self(less complicated)
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int a = 0, b = 0;
        bool first = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1)
                first = !first;
            if((i+1) % 6 == 0)
                first = !first;


            if(first)
                a += nums[i];
            else
                b += nums[i];
        }

        return (a-b);
    }
};