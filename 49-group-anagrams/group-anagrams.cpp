class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;

        for(int i = 0; i < copy.size(); i++){
            sort(copy[i].begin(), copy[i].end());
        }

        unordered_map<string, vector<int>> mpp;

        for(int i = 0; i < copy.size(); i++){
            mpp[copy[i]].push_back(i);
        }

        vector<vector<string>>ans(mpp.size());
        int i = 0;

        for(auto& [key, value] : mpp){
            for(int idx : value){
                ans[i].push_back(strs[idx]);
            }
            i += 1;
        }

        return ans;
    }
};