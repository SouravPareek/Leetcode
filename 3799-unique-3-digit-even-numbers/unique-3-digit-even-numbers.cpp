class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> vis(1000, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(digits[i] == 0)
                continue;
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                
                for(int k = 0; k < n; k++){
                    if(k == i || k == j || digits[k]%2)
                        continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(!vis[num]){
                        cnt += 1;
                        vis[num] = 1;
                    }
                }
            }
        }
        return cnt;
    }
};