class Solution {
    bool isVowel(char a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
            return true; 
        }
        return false;   
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
                cnt += 1;
        }
        return cnt;
    }
};