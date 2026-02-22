//self 
class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cnt = 0, last = -1;
        
        while(n > 0){
            cnt++;
            if(n % 2 == 1){
                if(last >= 0){
                    ans = max(ans, cnt-last);
                }
                last = cnt;
            }
            n /= 2;
        }
        return ans;
    }
};