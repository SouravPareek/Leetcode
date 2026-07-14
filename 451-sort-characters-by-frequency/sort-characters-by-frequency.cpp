class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for(char ch : s)
            mpp[ch] += 1;
        
        vector<pair<char, int>> vec;
        for(auto it : mpp)
            vec.push_back({it.first, it.second});
        
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        string ans = "";
        for(auto& it : vec){
            for(int i = 0; i < it.second; i++){
                ans += it.first;
            }
        }
        return ans;
    }
};