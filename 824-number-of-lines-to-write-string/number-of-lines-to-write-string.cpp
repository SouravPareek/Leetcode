class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();
        int lines = 1;
        int width = 0;

        for(int i = 0; i < n; i++){
            if(width + widths[s[i]-'a'] <= 100){
                width += widths[s[i]-'a'];
            }else{
                lines += 1;
                width = widths[s[i]-'a'];
            }
        }
        return {lines, width};
    }
};