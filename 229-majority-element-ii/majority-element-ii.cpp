//practice
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int it : nums)
            mpp[it] += 1;
        
        for(auto& it : mpp){
            if(it.second > n/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};