//brute force appraoch self
class Solution {
private:
    void generateBinaryStrings(unordered_set<string>& allStrings, string s, int n){
        if(s.length() == n){
            allStrings.insert(s);
            return ;
        }

        generateBinaryStrings(allStrings, s + '0', n);

        generateBinaryStrings(allStrings, s + '1', n);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        unordered_set<string> allStrings;

        generateBinaryStrings(allStrings, "", n);

        for(auto s : nums){
            if(allStrings.find(s) != allStrings.end()){
                allStrings.erase(s);
            }
        }
        string ans = "";
        if(allStrings.size() > 0)
            ans = *allStrings.begin();
        return ans;
    }
};