//self brute
class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n == 0)
            return false;
        
        string binary = "";
        while(n > 0){
            if(n%2 == 1)
                binary = '1' + binary;
            else
                binary = '0' + binary;
            
            n /= 2;
        }
        int cnt = 0;
        for(int i = 0; i < binary.size()-1; i++){
            if(binary[i] == '1' && binary[i+1] == '1')
                cnt += 1;
        }
        return cnt == 1;
    }
};