/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//self 
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> mpp;

        for(int it : nums)
            mpp[it] += 1;
        
        int cnt = 0;
        ListNode* temp = head;

        int seq = 0;

        while(temp){
            if(mpp.find(temp->val) != mpp.end()){
                if(seq == 0){
                    cnt += 1;
                }
                seq += 1;
            }else{
                seq = 0;
            }
            temp = temp->next;
        }
        return cnt;
    }
};