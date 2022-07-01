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
        int ct = 0;
        while(head != NULL)
        {
            ct++;
            head = head->next;
        }
        
        return ct;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode*newHead = head;
        
        int n = length(head);
        for(int i=0;i<n-1;i++)
        {
            ListNode*tail = newHead;
            while(tail -> next != NULL)
            {
                if(tail->val > tail->next->val)
                {
                    int a = tail->val;
                    tail->val = tail->next->val;
                    tail->next->val = a;
                }
                tail = tail->next;
            }
        }
        
        return head;
    }
};