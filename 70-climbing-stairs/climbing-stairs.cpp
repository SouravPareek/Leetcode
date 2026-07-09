//space optimization
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int prev2 = 1, prev = 2;
        int temp;

        for(int i = 3; i <= n; i++){
            temp = prev+prev2;
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};