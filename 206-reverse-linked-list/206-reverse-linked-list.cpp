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
    ListNode*glob;
    ListNode* reverse(ListNode*head)
{
//   base case
   if(head==NULL || head->next==NULL)
   {
       glob=head;
       return head;
   }

// recursive case
    ListNode *temp=head;
    ListNode*prev=reverse(head->next);
    temp->next=NULL;
    prev->next=temp;
        return temp;
}

    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return glob;
    }
};