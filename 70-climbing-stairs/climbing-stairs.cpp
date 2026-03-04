//self using tabulation with space optimized
class Solution {
public:
    int climbStairs(int n) {
        int step0 = 1;
        int step1 = 1;
        
        for(int i = 2; i <= n; i++){
            int ithStep = step0 + step1;
            step0 = step1;
            step1 = ithStep;
        }

        return step1;
    }
};