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
    ListNode* oddEvenList(ListNode* head) {
        bool flag = true;
        ListNode* temp = head;
        ListNode* evenHead = new ListNode(-1);
        ListNode* even = evenHead;
        ListNode* odd = new ListNode(-1);


        while(temp){
            if(flag){
                odd->next = temp;
                temp = temp->next;
                odd = odd->next;
                odd->next = nullptr;
                flag = false;
            }else{
                even->next = temp;
                temp = temp->next;
                even = even->next;
                even->next = nullptr;
                flag = true;
            }
        }

        if(evenHead->next)
            odd->next = evenHead->next;
        return head;
    }
};