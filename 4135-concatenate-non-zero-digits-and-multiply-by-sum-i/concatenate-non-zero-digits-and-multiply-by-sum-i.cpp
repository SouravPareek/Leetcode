//self brute
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;

        while(n > 0){
            int rem = n%10;

            sum += rem;

            if(rem != 0)
                x = x*10 + rem;

            n /= 10;
        }

        int num = 0;
        while(x > 0){
            num = num*10 + (x%10);
            x /= 10;
        }

        x = num;

        return x * sum;
    }
};