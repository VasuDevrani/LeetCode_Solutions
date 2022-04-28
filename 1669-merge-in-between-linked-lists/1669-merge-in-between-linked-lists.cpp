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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=0;
        ListNode*prev=list1;

        while(i<a-1)
        {
            i++;
            prev=prev->next;
        }

        ListNode*temp=prev->next;
        i=0;
        while(i<=b-a){
            i++;
            temp=temp->next;
        }
        // temp=temp->next;
        
        ListNode*del=prev;
        while(del->next!=temp)
        {
            ListNode*temp2=del->next->next;
            delete(del->next);
            del->next=temp2;        
        }
        
        prev->next=list2;
        ListNode*tail=list2;
        
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=temp;
        
        return list1;
            
            
    }
};