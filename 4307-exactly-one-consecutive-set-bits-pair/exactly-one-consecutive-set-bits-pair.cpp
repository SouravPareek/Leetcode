//self
class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary = "";
        int cnt = 0;
        bool prevSet = false;

        while(n > 0){
            char ch;
            if(n%2 == 1){
                ch = '1';
                if(prevSet)
                    cnt += 1;
                prevSet = true;
            }
            else{
                ch = '0';
                prevSet = false;
            }
            
            n /= 2;
        }
        return cnt == 1;
    }
};