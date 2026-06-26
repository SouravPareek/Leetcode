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
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());

                string num_str = "";
                while(!st.empty() && isdigit(st.top())){
                    num_str += st.top();
                    st.pop();
                }
                reverse(num_str.begin(), num_str.end());
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
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};