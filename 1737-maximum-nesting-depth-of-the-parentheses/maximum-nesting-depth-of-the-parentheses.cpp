class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, curr_depth = 0;

        for(char ch : s){
            if(ch == '(')
                curr_depth += 1;
            else if(ch == ')')
                curr_depth -= 1;
            
            max_depth = max(max_depth, curr_depth);
        }
        return max_depth;
    }
};