class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> oddHash(26, 0);
        vector<int> evenHash(26, 0);

        for(int i = 0; i < s1.length(); i++){
            if(i%2 == 0){
                evenHash[s1[i]-'a'] += 1;
                evenHash[s2[i]-'a'] -= 1;
            }else{
                oddHash[s1[i]-'a'] += 1;
                oddHash[s2[i]-'a'] -= 1;
            }
        }

        for(int i = 0; i < 26; i++){
            if(evenHash[i] != 0)
                return false;
            if(oddHash[i] != 0)
                return false;
        }

        return true;
    }
};