class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int>mpp;
        for(char ch : magazine)
            mpp[ch] += 1;
        for(char ch : ransomNote)
            mpp[ch] -= 1;

        for(auto &[key, value] : mpp){
            if(value < 0)
                return false;
        }
        return true;
    }
};