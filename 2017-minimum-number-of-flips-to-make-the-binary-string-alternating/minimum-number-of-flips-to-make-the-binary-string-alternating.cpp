//optimal approach using duplicate string and sliding window
class Solution {
public:
    int minFlips(string s) {
        string temp = s + s;
        int cnt1 = 0, cnt2 = 0;
        int ans = INT_MAX;
        int n = s.length();

        for(int i = 0; i < temp.length(); i++){
            char p1 = (i%2 == 0) ? '0' : '1';
            char p2 = (i%2 == 0) ? '1' : '0';
            
            if(temp[i] != p1)
                cnt1 += 1;
            if(temp[i] != p2)
                cnt2 += 1;
            
            if(i >= n){
                char prev = temp[i-n];

                char prev1 = ((i-n)%2 == 0) ? '0' : '1';
                char prev2 = ((i-n)%2 == 0) ? '1' : '0';

                if(prev != prev1)
                    cnt1 -= 1;
                if(prev != prev2)
                    cnt2 -= 1;
            }

            if(i >= n-1)
                ans = min(ans, min(cnt1, cnt2));
        }
        return ans;
    }
};