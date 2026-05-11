class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        
        int bracs = 0;

        for(char ch : s){
            if(ch == '[')
                bracs += 1;
            else if(bracs > 0)
                bracs -= 1;
        }
        return (bracs + 1)/2;
    }
};