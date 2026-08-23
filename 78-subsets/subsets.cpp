class Solution {
private:
    void helper(int idx, vector<int>& temp, vector<vector<int>> &ans, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        helper(idx+1, temp, ans, nums);
        temp.push_back(nums[idx]);
        helper(idx+1, temp, ans, nums);
        temp.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(0, temp, ans, nums);

        return ans;
    }
};