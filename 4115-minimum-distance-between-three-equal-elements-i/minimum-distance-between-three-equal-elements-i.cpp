class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist = INT_MAX;
        if(nums.size() < 3)
            return -1;
        for(int i = 0; i < nums.size()-2; i++){
            for(int j = i + 1; j < nums.size()-1; j++){
                if(nums[j] != nums[i])
                    continue;

                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[j] == nums[k]){
                        dist = min(dist, abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
                
            }
        }
        return (dist == INT_MAX) ? -1 : dist;
    }
};