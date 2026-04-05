class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> hash_char(26), hash_num(10);

        for(char ch : s){
            if(ch >= '0' && ch <= '9'){
                hash_num[ch-'0'] += 1;
            }else{
                hash_char[ch-'a'] += 1;
            }
        }

        int ans = 0;

        for(int i = 0; i < 13; i++){
            ans += abs(hash_char[i] - hash_char[25-i]);
        }

        for(int i = 0; i < 5; i++){
            ans += abs(hash_num[i] - hash_num[9-i]);
        }

        return ans;
    }
};