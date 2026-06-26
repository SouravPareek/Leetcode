//brute
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();

        set<int> allNums;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i != j && j != k && i != k && nums[i] != 0){
                        int num = 100*nums[i] + 10*nums[j] + nums[k];
                        allNums.insert(num);
                    }
                }
            }
        }

        vector<int> ans;

        for(int it : allNums){
            if(it%2 == 0){
                ans.push_back(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};