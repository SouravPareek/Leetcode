class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int cnt = 0;
        for(auto&[key, value] : mpp){
            if(value.size() != 3)
                continue;

            if(value[1]-value[0] == value[2]-value[1])
                cnt += 1;
        }
        return cnt;
    }
};