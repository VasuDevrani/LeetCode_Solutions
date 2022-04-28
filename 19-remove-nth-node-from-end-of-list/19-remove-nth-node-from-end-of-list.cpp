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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        if(head->next==NULL && n==1)
        {
            return NULL;
        }
        
        
//         if(n==1)
//         {
//             ListNode*tail=head;
//             while(tail->next->next!=NULL)
//             {
//                 tail=tail->next;
//             }
//             delete(tail->next);
//             tail->next=NULL;
//             return head;
//         }
        ListNode*s=head;
        ListNode*f=head;
        
        int temp=n;
        while(n--)
        {
            f=f->next;
        }
        
        if(f==NULL)
        {
            ListNode*start=head->next;
            delete(head);
            head=start;
            
            return head;
        }
        while(f->next!=NULL)
        {
            f=f->next;
            s=s->next;
        }
        
        f=s->next->next;
        delete(s->next);
        s->next=f;
        return head;
    }
};