class Solution {
private:
    string intTobinary(int n) {
        string temp = "";

        for (int i = 7; i >= 0; i--) {
            if (n & (1 << i))
                temp += '1';
            else
                temp += '0';
        }

        return temp;
    }

public:
    bool isPalindromic(string s) {
        int n = s.size();
        string temp = "";

        for (int i = 0; i < n; i++) {
            int ascii = s[i];

            temp += intTobinary(ascii);   
        }

        int l = 0, r = temp.size()-1;

        while(l <= r){
            if(temp[l] != temp[r])
                return false;
            
            l += 1;
            r -= 1;
        }

        return true;
    }
};