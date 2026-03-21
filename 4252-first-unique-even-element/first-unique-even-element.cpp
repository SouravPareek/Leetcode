//self
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]] += 1;
        }

        for(int it : nums){
            if(it%2 == 0 && mpp[it] == 1)
                return it;
        }
        return -1;
    }
};