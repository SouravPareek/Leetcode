class Solution {
private:
    int sumDigit(int n){
        if(n == 0)
            return 0;
        return n%10 + sumDigit(n/10);
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(sumDigit(nums[i]) == i)
                return i;
        }
        return -1;
    }
};