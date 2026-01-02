//self
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        //use map to count the frequency of each element
        map<int, int> hash;

        //count freq for each element and store in map
        for(int it : nums)
            hash[it]++;
        
        //check freq of each element and find one with freq equal to n/2 and return it
        for(auto x : hash){
            if(x.second == nums.size()/2)
                return x.first;
        }
        return 0;
    }
};

//T.C : O(n), where n is size of the nums array
//S.C : O(n), space used by hash map to store freq for each element