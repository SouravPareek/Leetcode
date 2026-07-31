//self approach
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
            if(freq[i] > 0)
                arr.push_back({i+'a', freq[i]});
        }

        sort(arr.begin(), arr.end(), [](const pair<char, int> a, const pair<char, int> b){
            return a.second > b.second;
        });

        int idx = 0;
        unordered_set<char> st1;
        unordered_set<char> st2;
        unordered_set<char> st3;
        unordered_set<char> st4;
        for(int i = 0; i < arr.size(); i++){
            if(idx <= 7)
                st1.insert(arr[i].first);
            else if(idx <= 15)
                st2.insert(arr[i].first);
            else if(idx <= 23)
                st3.insert(arr[i].first);
            else
                st4.insert(arr[i].first);
            idx += 1;
        }

        int ans = 0;
        for(char ch : word){
            if(st1.find(ch) != st1.end())
                ans += 1;
            else if(st2.find(ch) != st2.end())
                ans += 2;
            else if(st3.find(ch) != st3.end())
                ans += 3;
            else
                ans += 4;
        }

        return ans;
    }
};