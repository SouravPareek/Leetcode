//self
class Solution {
public:
    int maxDistinct(string s) {
        int ans = 0;
        //hashing to track the occurence of each char in the string
        //number of unique characters appearedd in the array is our answer as we can get substrings from each character.
        vector<int> hash(26, 0);
        for(char c : s){
            //if a char appears for first time then it's firs occurence counts as unique so add one to the ans
            if(hash[c-'a'] == 0)
                ans += 1;
            //count the number of occurences
            hash[c-'a'] += 1;
        }

        return ans;
    }
};

//T.C : O(n), as the string is trversed once
//S.C : O(26), for hash array