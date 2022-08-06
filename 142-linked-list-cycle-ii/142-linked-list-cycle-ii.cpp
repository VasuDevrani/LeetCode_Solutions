/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        
        unordered_set<ListNode*>s;
        while(head -> next != NULL)
        {
            if(s.find(head) != s.end())
            {
                return head;
            }
            s.insert(head);
            head = head->next;
        }
        return NULL;
    }
};