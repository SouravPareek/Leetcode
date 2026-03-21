//self
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> hash(101, 0);

        for(int it : nums){
            hash[it] += 1;
        }

        for(int it : nums){
            if(it%2 == 0 && hash[it] == 1)
                return it;
        }
        return -1;
    }
};