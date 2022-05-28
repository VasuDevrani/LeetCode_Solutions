/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode*head)
    {
        int ct=0;
        while(head!=NULL)
        {
            ct++;
            head=head->next;
        }
        return ct;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int l1=length(headA);
        int l2=length(headB);
        int diff=abs(l2-l1);
        if(l2>l1)
        {
            while(diff--)
            {
                headB=headB->next;
            }
        }
        else{
            while(diff--)
                headA=headA->next;
        }
        while(headA!=NULL && headB!=NULL)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        
        return NULL;
    }
};