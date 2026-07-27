//self
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int it : nums)
            pq.push(it);
        
        int ans = 1;
        ans *= (pq.top()-1);
        pq.pop();

        return ans*(pq.top()-1);
    }
};