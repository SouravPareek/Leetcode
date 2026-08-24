class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> hash(upper-lower+1, 0);
        for(int it : nums){
            if(it >= lower && it <= upper)
                hash[it-lower] = 1;
        }

        vector<vector<int>> ans;

        int n = hash.size(), i = 0;
        while(i < n){
            if(!hash[i]){
                int st = i;

                while(i < n && !hash[i])
                    i += 1;
                
                ans.push_back({st+lower, i+lower-1});
            }else{
                i += 1;
            }
        }
        return ans;
    }
};