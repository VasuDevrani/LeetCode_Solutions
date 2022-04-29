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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*head1=NULL;
     
         head1=head->next;
         int i=0;
         ListNode*List=head1;
        while(head!=NULL && head->next!=NULL)
        {
            if(i!=0)
            head1->next=head->next;
            ListNode*temp=head;
            head=head->next->next;
            if(i!=0)
             head1=head1->next;
            head1->next=temp;
            head1=head1->next;
            head1->next=NULL;
            i++;
        }
        if(head!=NULL)
        {
            head1->next=head;
        }
        
        return List;
    }
};