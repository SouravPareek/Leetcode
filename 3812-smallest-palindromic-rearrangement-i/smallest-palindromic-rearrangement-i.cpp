//optimal
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        int n = s.length();

        for(int i = 0; i < n/2; i++){
            freq[s[i]-'a'] += 1;
        }

        int idx = 0;
        for(int i = 0; i < 26; i++){
            while(freq[i]-- > 0){
                s[idx] = (char)(i+'a');
                idx += 1;
            }
        }

        for(int i = 0; i < n/2; i++){
            s[n-1-i] = s[i];
        }

        return s;
    }
};