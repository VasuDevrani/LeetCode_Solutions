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
    void insertAtHead(ListNode*&head,int d)
    {
        if(head==NULL)
        {
            head=new ListNode(d);
            return;
        }
        ListNode*temp=new ListNode(d);
        temp->next=head;
        head=temp;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>num1;
        stack<int>num2;
        
        while(l1!=NULL)
        {
            num1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            num2.push(l2->val);
            l2=l2->next;
        }
        
        ListNode*head=NULL;
        int k=0;
        int sum=0;
        
        while(!num1.empty() && !num2.empty())
        {
            int sum=num1.top()+num2.top()+k;
            insertAtHead(head,sum%10);
            
            k=sum/10;
            num1.pop();
            num2.pop();
        }
        while(!num1.empty())
        {
            int sum=num1.top()+k;
            insertAtHead(head,sum%10);
            
            k=sum/10;
            num1.pop();
        }
        while(!num2.empty())
        {
            int sum=num2.top()+k;
            insertAtHead(head,sum%10);
            
            k=sum/10;
            num2.pop();
        }
        if(k!=0)
        insertAtHead(head,k);
        
        return head;    
    }
};