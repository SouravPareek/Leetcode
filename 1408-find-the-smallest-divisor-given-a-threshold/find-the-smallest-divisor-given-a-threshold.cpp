class Solution {
private:
    int helper(vector<int>& nums, int a){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += (nums[i]+a-1)/a;
        }
        return ans;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        if (threshold <= nums.size()){
            return high;
        }

        int ans = high;

        while(low <= high){
            int mid = (high-low)/2 + low;

            if(helper(nums, mid) <= threshold){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1; 
            }
        }
        return ans;
    }
};