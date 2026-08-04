class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0], maxi = nums[0];

        unordered_set<int> st;
        for(int it : nums){
            st.insert(it);
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        vector<int> ans;
        for(int i = mini+1; i < maxi; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};