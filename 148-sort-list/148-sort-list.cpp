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
    
    ListNode*midpoint(ListNode*head)
    {
        ListNode*s=head;
        ListNode*f=head->next;
        
        while(f!=NULL && f->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    
    ListNode*merge(ListNode*a,ListNode*b)
    {
       if(a==NULL)
            return b;
       if(b==NULL)
       return a;

       ListNode*c;
       if(a->val<b->val)
       {
           c=a;
           c->next=merge(a->next,b);
       }
        if(a->val>=b->val)
       {
           c=b;
           c->next=merge(a,b->next);
       }
       return c;
        
    }
    
    ListNode*merge_sort(ListNode*head)
    {
//         base case
        if(head==NULL || head->next==NULL)
            return head;
           
//         recursive case
        ListNode*mid=midpoint(head);
        ListNode*left=mid->next;
        mid->next=NULL;
        
        ListNode*a=merge_sort(head);
        ListNode*b=merge_sort(left);
        ListNode*c;
        
        c=merge(a,b);
        return c;
    }
    
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};