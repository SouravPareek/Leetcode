//bit more cleaner code(space optimized)
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch-'a'] += 1;
        }

        vector<pair<int,int>> arr;

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                arr.push_back({freq[i], i});
        }

        sort(arr.begin(), arr.end(), greater<>());

        vector<int> pos(26, 0);
        for(int i = 0; i < arr.size(); i++){
            pos[arr[i].second] = (i/8) + 1;
        }

        int ans = 0;
        for(char ch : word){
            ans += pos[ch-'a'];
        }

        return ans;
    }
};