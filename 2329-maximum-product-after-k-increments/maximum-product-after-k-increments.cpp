class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int mod = 1e9 + 7;

        for(int it : nums){
            pq.push(it);
        }

        while(k--){
            int num = pq.top();
            pq.pop();
            num += 1;
            pq.push(num);
        }

        long long prod = 1;

        while(!pq.empty()){
            prod *= pq.top();
            prod %= mod;
            pq.pop();
        }
        return (int)(prod%mod);
    }
};