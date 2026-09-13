class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int cnt = 0;
        for(auto&[key, value] : mpp){
            if(value.size() < 3)
                continue;
            bool flag = true;
            for(int i = 1; i < value.size()-1; i++){
                if(value[i]-value[i-1] != value[i+1]-value[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cnt += 1;
        }
        return cnt;
    }
};