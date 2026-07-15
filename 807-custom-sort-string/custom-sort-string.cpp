//self
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mpp;

        for(char ch : s){
            mpp[ch] += 1;
        }

        string ans = "";
        for(char ch : order){
            if(mpp.find(ch) != mpp.end()){
                for(int i = 0; i < mpp[ch]; i++)
                    ans += ch;
                mpp[ch] = 0;
            }
        }

        for(auto& it : mpp){
            if(it.second > 0){
                for(int i = 0; i < it.second; i++)
                    ans += it.first;
            }
        }
        return ans;
    }
};