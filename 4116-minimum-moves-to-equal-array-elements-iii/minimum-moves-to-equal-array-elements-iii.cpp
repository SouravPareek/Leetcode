class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int it : nums){
            maxi = max(maxi, it);
            sum += it;
        }
        
        return maxi*nums.size()-sum;
    }
};