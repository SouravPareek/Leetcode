class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        unordered_map<char, int> mpp;

        int ans = 0;
        for(int j = 0; j < n; j++){
            mpp[s[j]] += 1;
            while(mpp[s[j]] > 1){
                mpp[s[i]] -= 1;
                i += 1;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};