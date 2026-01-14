class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> st;
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                st.insert(nums[j]);
                sum += nums[j];
                if(st.find(sum) != st.end())
                    cnt += 1;
            }
        }
        return cnt;
    }
};