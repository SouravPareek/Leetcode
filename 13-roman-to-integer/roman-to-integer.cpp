class Solution {
private:
    int value(char ch){
        if(ch == 'I')
            return 1;
        if(ch == 'V')
            return 5;
        if(ch == 'X')
            return 10;
        if(ch == 'L')
            return 50;
        if(ch == 'C')
            return 100;
        if(ch == 'D')
            return 500;
        return 1000;
    }
public:
    int romanToInt(string s) {
        stack<pair<char, int>> st;
        for(char ch : s){
            if(st.empty() || st.top().second >= value(ch)){
                st.push({ch, value(ch)});
            }else{
                int val = 0;
                while(!st.empty() && st.top().second < value(ch)){
                    val -= st.top().second;
                    st.pop();
                }
                st.push({ch, value(ch)+val});
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top().second;
            st.pop();
        }
        return ans;
    }
};