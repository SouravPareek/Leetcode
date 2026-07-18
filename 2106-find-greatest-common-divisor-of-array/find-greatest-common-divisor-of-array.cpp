class Solution {
private:
    //considering a is always smaller number
    int gcd(int a, int b){
        if(a == 0)
            return b;
        return gcd(b%a, a);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0], maxi = nums[0];

        for(int it : nums){
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        return gcd(mini, maxi);
    }
};