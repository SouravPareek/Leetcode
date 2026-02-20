//self approach using 32 bit int
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int remainder = 0;

        while(x){
            if(ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;
            remainder = x%10;
            ans = ans*10+remainder;
            x /= 10;
        }

        return ans;
    }
};