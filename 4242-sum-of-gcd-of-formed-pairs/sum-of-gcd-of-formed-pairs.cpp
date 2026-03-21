//self
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = INT_MIN;
        vector<int> pref(n, 0);

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);

            pref[i] = gcd(nums[i], mx);
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        int left = 0;
        int right = n-1;

        while(left < right){
            ans += gcd(pref[left], pref[right]);
            left += 1;
            right -= 1;
        }

        return ans;
    }
};