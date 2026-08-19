class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int lMax = 0, rMax = 0;
        int ans = 0;

        while(l < r){
            rMax = max(rMax, height[r]);
            lMax = max(lMax, height[l]);

            if(rMax < lMax){
                ans += rMax-height[r];
                r -= 1;
            }else{
                ans += lMax-height[l];
                l += 1;
            }
        }
        return ans;
    }
};