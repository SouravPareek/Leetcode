//self
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size(), m = discounts.size();
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        double ans = 0;
        int i = n-1, j = m-1;

        while(i >= 0){
            if(j >= 0){
                ans += (prices[i]*(100.0-discounts[j]))/100;
                j -= 1;
            }else{
                ans += prices[i];
            }
            i -= 1;
        }
        return ans;
    }
};