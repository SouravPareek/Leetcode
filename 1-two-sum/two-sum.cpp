class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for(int i = 0; i < n; i++){
            int comp = target - nums[i];
            if(hash.find(comp) != hash.end() && hash[comp] != i)
                return {hash[comp], i};
            
            hash[nums[i]] = i;
        }
        return {};
    }
};