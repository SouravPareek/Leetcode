class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        for (int it : nums)
            numStrings.push_back(to_string(it));

        sort(numStrings.begin(), numStrings.end(), [](string a, string b) {
            return a+b > b+a;
        });

        if(numStrings[0] == "0")
            return "0";

        string ans = "";
        for (auto str : numStrings)
            ans += str;

        return ans;
    }
};