class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string temp = s1;

        if(s1 == s2)
            return true;
        
        swap(s1[0], s1[2]);
        if(s1 == s2)
            return true;
        
        s1 = temp;
        swap(s1[1], s1[3]);
        if(s1 == s2)
            return true;

        s1 = temp;
        swap(s1[1], s1[3]);
        swap(s1[0], s1[2]);
        if(s1 == s2)
            return true;
        
        return false;
    }
};