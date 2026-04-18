class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int n = num;

        while(num > 0){
            if(n % (num%10) == 0)
                cnt += 1;
            
            num /= 10;
        }
        return cnt;
    }
};