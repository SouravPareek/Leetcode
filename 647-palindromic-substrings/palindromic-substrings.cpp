//self brute
class Solution {
private:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;

        while(i <= j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            string test = "";
            for(int j = i; j < s.length(); j++){
                test += s[j];

                if(isPalindrome(test))
                cnt += 1;
            }
        }

        return cnt;
    }
};