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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp=NULL;
        ListNode*head=NULL;
        
        long long ct=0;
        long long sum=0;
        
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            
            sum+=ct;
            if(temp==NULL)
            {
                temp=new ListNode(sum%10);
                head=temp;
                ct=sum/10;
                sum=0;
            }
            else
            {
                ListNode*newnode=new ListNode(sum%10);
                temp->next=newnode;
                temp=temp->next;
                ct=sum/10;
                sum=0;
            }
        }
        if(ct!=0)
        {
            ListNode*newnode=new ListNode(ct);
                temp->next=newnode;
                temp=temp->next;
        }
        return head;
    }
};