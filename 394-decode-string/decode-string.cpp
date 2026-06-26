class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string ans = "";

        stack<char>st;

        for(int i = 0; i < n; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }else{
                string temp = "";
                while(st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();

                string num_str = "";
                while(!st.empty() && isdigit(st.top())){
                    num_str = st.top() + num_str;
                    st.pop();
                }
                int num = stoi(num_str);

                string part = "";
                for(int j = 0; j < num; j++){
                    part += temp;
                }

                for(int j = 0; j < part.size(); j++){
                    st.push(part[j]);
                }
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};