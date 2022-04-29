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
    ListNode* mergeNodes(ListNode* head) {
      
        ListNode*ans=new ListNode(0);
        ListNode*newhead=ans;
        
        head=head->next;
        
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                ans->val+=head->val;
                head=head->next;
            }
            else if(head->val==0 && head->next!=NULL)
            {
                head=head->next;
                ListNode*temp=new ListNode(0);
                ans->next=temp;
                ans=ans->next;
            }
            else
                 head=head->next;
        }
        return newhead; 
        
    }
};