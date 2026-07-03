class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        for(char& c : s)
            c = tolower(c);

        string temp = "";

        for(char& ch : s){
            if(ch >= 'a' && ch <= 'z' || ch >='0' && ch <='9')
                temp += ch;
        }

        int left = 0, right = temp.length()-1;

        while(left < right){
            if(temp[left] != temp[right])
                return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};