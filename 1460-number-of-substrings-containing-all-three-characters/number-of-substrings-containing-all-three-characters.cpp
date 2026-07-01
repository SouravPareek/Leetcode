//brute
class Solution {
private:
    bool helper(vector<int>& freq){
        return (freq[0] > 0 && freq[1] > 0 && freq[2] > 0);
    }
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int left = 0, right = 0;
        int cnt = 0;

        vector<int> freq(3, 0);

        while(right < n){
            freq[s[right]-'a'] += 1;

            while(helper(freq)){
                cnt += n - right;

                freq[s[left]-'a'] -= 1;
                left++;
            }
            right += 1;
        }
        return cnt;
    }
};