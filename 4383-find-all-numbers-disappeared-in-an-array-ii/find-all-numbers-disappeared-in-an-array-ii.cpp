class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<vector<int>> ans;

        if (nums.size() == 0)
            return {{lower, upper}};

        unordered_set<int> st(nums.begin(), nums.end());

        int curr_low = -1;
        int curr_high = -1;

        for (int i = lower; i < upper; i++) {
            if (st.find(i) == st.end()) {
                if (curr_low == -1) {
                    curr_low = i;
                }
                curr_high = i;
            } else {
                if (curr_low != -1) {
                    ans.push_back({curr_low, curr_high});
                }
                curr_low = -1;
                curr_high = -1;
            }
        }
        if (st.find(upper) == st.end()) {
            if(curr_low != -1){
                ans.push_back({curr_low, upper});
            }else{
                ans.push_back({upper, upper});
            }
        } else {
            if (curr_low != -1) {
                ans.push_back({curr_low, curr_high});
            }
        }

        return ans;
    }
};