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
        int ct=0;
        while(head!=NULL)
        {
            ct++;
            head=head->next;
        }
        return ct;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int n=length(head);
        int arr[n];
        
        for(int i=1;i<=n;i++)
        {
            if(i+k<=n)
            {
                arr[i+k-1]=head->val;
            }
            else
            {
                int pos=(i+k)%n;
                if(pos!=0)
                arr[pos-1]=head->val;
                else
                    arr[n-1]=head->val;
            }
            head=head->next;
        }
        
        ListNode*nhead=new ListNode(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            ListNode*temp=new ListNode(arr[i]);
            temp->next=nhead;
            nhead=temp;
        }
        
        return nhead;
    }
};