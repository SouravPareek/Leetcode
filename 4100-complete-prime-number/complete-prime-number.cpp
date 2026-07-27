//self
class Solution {
private:
    bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2)
            return true;
        if(n%2 == 0)
            return false;
        
        for(int i = 3; i <= sqrt(n); i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
public:
    bool completePrime(int num) {
        if(!isPrime(num))
            return false;

        //suffix
        int n = num;
        long long divisor = 10;
        while(n > 0){
            int rem = n%10;
            if(!isPrime(num%divisor))
                return false;
            divisor *= 10;
            n /= 10;
        }

        //prefix
        n = num;
        long long div = 1;
        while (div <= n / 10)
            div *= 10;

        while (div > 0) {
            if(!isPrime(n/div))
                return false;
            div /= 10;
        }

        return true;
    }
};