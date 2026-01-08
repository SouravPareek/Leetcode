//self
class Solution {
public:
    string reversePrefix(string s, int k) {
        string ans = "";
        string temp = "";
        for(int i = 0; i < k; i++){
            temp += s[i];
        }
        reverse(temp.begin(), temp.end());

        ans += temp;
        for(int i = k; i < s.length(); i++)
            ans += s[i];
        
        return ans;
    }
};