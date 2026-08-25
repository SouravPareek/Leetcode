class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for(int it : nums){
            mpp[it] += 1;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }

        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k -= 1;
        }
        return ans;
    }
};