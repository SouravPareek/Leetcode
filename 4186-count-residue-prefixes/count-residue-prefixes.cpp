class Solution {
public:
    int residuePrefixes(string s) {
        int cnt = 0;
        unordered_set<int> st;
        for(int i = 0; i < s.length(); i++){
            st.insert(s[i]);
            if(st.size() == (i+1)%3)
                cnt += 1;
        }
        return cnt;
    }
};