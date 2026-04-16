class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash(26);
        for(int i = 0; i < s.length(); i++){
            hash[t[i]-'a'] += 1;
            hash[s[i]-'a'] -= 1;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += max(0, hash[i]);
        }
        return ans;
    }
};