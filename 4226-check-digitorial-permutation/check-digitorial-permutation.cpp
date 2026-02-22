//self
class Solution {
private:
    int Digitorial(int n){
        int ans = 0;
        while(n > 0){
            ans += factorial(n%10);
            n /= 10;
        }
        return ans;
    }
    int factorial(int n){
        if(n <= 1)
            return 1;
        
        return n*factorial(n-1);
    }
public:
    bool isDigitorialPermutation(int n) {
        string s = to_string(n);

        sort(s.begin(), s.end());


        do {
            if (s[0] != '0') {
                if(stoi(s) == Digitorial(n))
                    return true;
            }
        } while (next_permutation(s.begin(), s.end()));
        
        return false;
    }
};