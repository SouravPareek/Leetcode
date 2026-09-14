//self better
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>>st;

        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n-2; j++){
                int l = j+1, r = n-1;

                while(l < r){
                    long long sum = (long long)nums[i]+ (long long)nums[j]+ (long long)nums[l]+ (long long)nums[r];
                    
                    if(sum <= target){
                        if(sum == target)
                            st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l += 1;
                    }else{
                        r -= 1;
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};