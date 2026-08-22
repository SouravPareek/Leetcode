class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_mpp;
        unordered_map<char, int> t_mpp;

        for(int i = 0; i < s.size(); i++){
            if(s_mpp.find(s[i]) == s_mpp.end()){
                s_mpp[s[i]] = i;
            }

            if(t_mpp.find(t[i]) == t_mpp.end()){
                t_mpp[t[i]] = i;
            }

            if(s_mpp[s[i]] != t_mpp[t[i]])
                return false;
        }
        return true;
    }
};