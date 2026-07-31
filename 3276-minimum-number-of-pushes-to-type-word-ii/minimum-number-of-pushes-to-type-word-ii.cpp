//bit cleaner code(space optimized)
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch-'a'] += 1;
        }

        vector<pair<char,int>> arr;

        for(int i = 0; i < 26; i++){
            arr.push_back({i+'a', freq[i]});
        }

        sort(arr.begin(), arr.end(), [](const pair<char, int> a, const pair<char, int> b){
            return a.second > b.second;
        });

        vector<int> pos(26, 0);
        for(int i = 0; i < arr.size(); i++){
            pos[arr[i].first-'a'] = (i/8) + 1;
        }

        int ans = 0;
        for(char ch : word){
            ans += pos[ch-'a'];
        }

        return ans;
    }
};