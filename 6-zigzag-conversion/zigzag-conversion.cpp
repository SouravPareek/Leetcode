class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1 || numRows == n)
            return s;
        
        vector<string> rows(numRows, "");
        bool isgoingDown = true;
        int row = 0;

        for(int i = 0; i < n; i++){
            if(i != 0 && row == 0){
                isgoingDown = true;
                row = 0;
            }else if(row == numRows-1){
                isgoingDown = false;
                row = numRows-1;
            }

            if(isgoingDown){
                rows[row] += s[i];
                row += 1;
            }else{
                rows[row] += s[i];
                row -= 1;
            }
        }

        string ans = "";
        for(auto row: rows){
            ans += row;
        }
        return ans;
    }
};