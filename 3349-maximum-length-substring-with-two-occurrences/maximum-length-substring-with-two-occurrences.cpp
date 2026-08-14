//self
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int ans = 0;

        while(j < n){
            mpp[s[j]] += 1;

            while(mpp[s[j]] > 2){
                mpp[s[i]] -= 1;
                i += 1;
            }
            ans = max(ans, j-i+1);
            j += 1;
        }
        return ans;
    }
};