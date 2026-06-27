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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;

        while(a != 1){
            temp = temp->next;
            a--;
            b--;
        }
        ListNode* node = temp;

        while(b--){
            temp = temp->next;
        }
        ListNode* last = temp->next;

        node->next = list2;

        temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = last;

        return list1;
    }
};