//editorial optimal
class Solution {
private:
    int cntPalindrome(string s, int st, int end){
        int cnt = 0;
        while(st>= 0 && end < s.length() && s[st--] == s[end++]){
            cnt++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            ans += cntPalindrome(s, i, i);
            ans += cntPalindrome(s, i, i+1);
        }

        return ans;
    }
};