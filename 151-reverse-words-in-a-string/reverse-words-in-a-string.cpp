class Solution {
private:
    void reverse(string& s, int start, int end) {
        while (start < end)
            swap(s[start++], s[end--]);
    }

public:
    string reverseWords(string s) {
        int n = s.size();

        reverse(s, 0, n - 1);

        int i = 0, j = 0, start, end;

        while (j < n) {
            while (j < n && s[j] == ' ')
                j += 1;

            if (j >= n)
                break;

            start = i;

            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            
            end = i-1;
            reverse(s, start, end);

            if (j < n) {
                s[i++] = ' ';
            }
        }
        if (i > 0 && s[i - 1] == ' ')
            i -= 1;
            
        return s.substr(0, i);
    }
};