//optimal
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(char ch : magazine)
            freq[ch-'a'] += 1;
        for(char ch : ransomNote)
            freq[ch-'a'] -= 1;

        for(int it: freq){
            if(it < 0)
                return false;
        }
        return true;
    }
};