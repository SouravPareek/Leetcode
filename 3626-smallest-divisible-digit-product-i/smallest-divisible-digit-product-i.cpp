class Solution {
private:
    bool check(int n, int t){
        int prod = 1;

        while(n > 0){
            prod *= (n%10);

            n /= 10;
        }
        return !(prod % t);
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            if(check(n, t)){
                break;
            }
            n += 1;
        }
        return n;
    }
};