//self approach
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        int remainder = 0;

        while(x){
            remainder = x%10;
            ans = ans*10+remainder;
            x /= 10;
        }
        
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;

        return ans;
    }
};