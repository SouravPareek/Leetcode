//self
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        //if k > n it means more than k elements must be greater, that's not possible for any of numbers thus return 0
        if(k > n)
            return 0;

        //if k = 0 then all elements have at leasst 0 elments greater then it , thus return 0
        if(k == 0)
            return n;
        
        //sort to easse the process of looping
        sort(nums.begin(), nums.end());

        //kth largest num will be greater than or equal to all the elements before it as nums is sorted
        int kthLargest = nums[n-k];
        int ans = 0;
        
        //loop to check lesser or equal as we need to count for only elements less then kth largest
        for(int i = 0; i < n-k; i++){
            if(nums[i] < kthLargest)
                ans += 1;
        }
        return ans;
    }
};

//T.C : O(nlogn), due to sorting and O(n-k) for looping which sum up to O(nlogn)
//S.C : O(1), as no extra space is used