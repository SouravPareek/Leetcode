class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for(int it : nums)
            mpp[it] += 1;
        
        vector<pair<int, int>> vec;
        for(auto it : mpp)
            vec.push_back({it.first, it.second});
        
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        vector<int> ans(k, 0);
        int i = 0;

        for(auto& it : vec){
            if(k == i)
                break;
            ans[i++] = it.first;
        }
        return ans;
    }
};