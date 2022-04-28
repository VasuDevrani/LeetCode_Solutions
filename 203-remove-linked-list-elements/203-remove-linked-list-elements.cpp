/*
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        ListNode*temp=head;
        
        while(temp!=NULL)
        {
            if(temp->next!=NULL){
            if(temp->next->val==val)
            {
                ListNode*dup=temp->next->next;
                delete(temp->next);
                temp->next=dup;
            }
                 else
                temp=temp->next;
            }
            else
                temp=temp->next;
        }
        if(head->val==val)
        {
            ListNode*dup=head->next;
            delete(head);
            head=dup;
        }
        return head;
    }
};