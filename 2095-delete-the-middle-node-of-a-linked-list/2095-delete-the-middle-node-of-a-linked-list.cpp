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
    
    int length(ListNode*head)
    {
        int c=0;
        while(head!=NULL)
        {
            head=head->next;
            c++;
        }
        return c;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        int half=length(head)/2;
        if(half==0)
        {
            delete(head);
            ListNode*n=NULL;
            return n;
        }
        
        ListNode*temp=head;
        for(int i=0;i<half-1;i++)
        {
            temp=temp->next;
        }
        ListNode*forward=temp->next->next;
        delete(temp->next);
        temp->next=forward;
        return head;
        
    }
};