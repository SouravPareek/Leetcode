class Solution {
private:
    bool check(char open, char close){
        if((open == '(' && close == ')')||
            (open == '{' && close == '}')||
            (open == '[' && close == ']'))
            return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty())
                    return false;
                
                if(check(st.top(), ch)){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};