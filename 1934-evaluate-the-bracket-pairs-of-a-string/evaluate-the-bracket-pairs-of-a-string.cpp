class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto pair : knowledge){
            mpp[pair[0]] = pair[1];
        }

        string ans = "";
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                string key = "";
                i += 1;
                while(s[i] != ')'){
                    key += s[i];
                    i += 1;
                }
                i += 1;

                if(mpp[key] == "")
                    ans += '?';
                else
                    ans += mpp[key];
            }else{
                ans += s[i];
                i += 1;
            }
        }
        return ans;
    }
};