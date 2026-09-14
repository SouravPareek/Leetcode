// self optimal
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int best = nums[0]+nums[1]+nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - best)) 
                    best = sum;

                if(sum < target)
                    l += 1;
                else if(sum > target)
                    r -= 1;
                else
                    return target;
            }
        }
        return best;
    }
};