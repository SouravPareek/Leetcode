//optimal practice
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        if(n == 0)
            return ans;
        if(n == 1)
            return nums;
        
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;

        for(int ele : nums){
            if(ele == ele1)
                cnt1 += 1;
            else if(ele == ele2)
                cnt2 += 1;
            else if(cnt1 == 0){
                ele1 = ele;
                cnt1 += 1;
            }else if(cnt2 == 0){
                ele2 = ele;
                cnt2 += 1;
            }else{
                cnt1 -= 1;
                cnt2 -= 1;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(int it : nums){
            if(it == ele1)
                cnt1 += 1;
            else if(it == ele2)
                cnt2 += 1;
        }

        if(cnt1 > (n/3))
            ans.push_back(ele1);
        if(cnt2 > (n/3))
            ans.push_back(ele2);
        
        return ans;
    }
};