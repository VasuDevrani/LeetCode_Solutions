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
    ListNode* deleteDuplicates(ListNode* head) {
       ListNode *thead=head;
       while(thead!=NULL)
       {
           if(thead->next!=NULL && thead->next->val==thead->val)
           {
               ListNode*temp=thead->next->next;
               delete(thead->next);
               thead->next=temp;
           }
           else
              thead=thead->next; 
       }
        return head;
    }
};