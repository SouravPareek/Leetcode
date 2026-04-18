class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        while(low <= high){
            if(low%2 == 1)
                cnt += 1;
            if(high != low && high%2 == 1)
                cnt += 1;
            
            low += 1;
            high -= 1;
        }
        return cnt;
    }
};