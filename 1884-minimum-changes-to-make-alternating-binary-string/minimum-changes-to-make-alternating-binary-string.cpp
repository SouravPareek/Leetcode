//self
class Solution {
public:
    int minOperations(string s) {
        int StartWithZero = 0, StartWithOne = 0;
        for(int i = 0; i < s.length(); i++){
            if(i%2 == 0){
                if(s[i] != '0')
                    StartWithZero += 1;
                else
                    StartWithOne += 1;
            }else{
                if(s[i] == '0')
                    StartWithZero += 1;
                else
                    StartWithOne += 1;
            }
        }
        return min(StartWithOne, StartWithZero);
    }
};