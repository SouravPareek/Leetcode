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

 //cleaner
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        ListNode* tail = head;

        int cnt = 1;
        while(tail->next){
            cnt += 1;
            tail = tail->next;
        }
        tail->next = head;

        k = k%cnt;

        if(k == 0){
            tail->next = nullptr;
            return head;
        }

        tail = head;

        int breaking_point = cnt-k-1;

        while(breaking_point--){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};