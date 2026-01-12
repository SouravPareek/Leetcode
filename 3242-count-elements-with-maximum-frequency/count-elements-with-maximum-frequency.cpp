class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int it : nums)
            mpp[it] += 1;
        
        int maxFreq = 0;
        for(auto [num, freq] : mpp){
            maxFreq = max(maxFreq, freq);
        }
        int cnt = 0;

        for(auto [num, freq] : mpp){
            if(freq == maxFreq)
                cnt += 1;
        }
        return cnt*maxFreq;
    }
};