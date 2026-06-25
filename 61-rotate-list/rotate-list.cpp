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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        ListNode* temp = head;

        int cnt = 0;
        while(temp->next){
            cnt += 1;
            temp = temp->next;
        }
        if(temp){
            cnt += 1;
        }
        temp->next = head;

        k = k%cnt;
        temp = head;

        int breaking_point = cnt-k-1;

        while(breaking_point--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};