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
    ListNode* swapNodes(ListNode* head, int k) {
        int temp=k-1;
        ListNode*first=head;
            
        while(temp--)
        {
            first=first->next;
        }
        
        ListNode*s=head;
        ListNode*f=head;
        
        f=first;
        
        while(f->next!=NULL)
        {
            f=f->next;
            s=s->next;
        }
        
        temp=s->val;
        s->val=first->val;
        first->val=temp;
        
        return head;
    }
};