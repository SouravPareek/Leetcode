//self
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char ch : s)
            freq[ch-'a'] += 1;
        string firstHalf = "";
        char mid = 'A';

        for(int i = 0; i < 26; i++){
            while(freq[i] > 1){
                char ch = i + 'a';
                firstHalf += ch;
                freq[i] -= 2;
            }
            if(freq[i] == 1)
                mid = i+'a';
        }

        string ans = firstHalf + ((mid != 'A') ? string(1, mid) : "");

        reverse(firstHalf.begin(), firstHalf.end());

        ans += firstHalf;
        return ans;
    }
};