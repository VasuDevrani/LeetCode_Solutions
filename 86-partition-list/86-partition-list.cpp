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
    ListNode* partition(ListNode* head, int x) {
        vector<int>small, large;
        
        ListNode*node = head;
        while(node != NULL)
        {
            if(node->val >= x)
                large.push_back(node->val);
            else
                small.push_back(node->val);
            
            node = node->next;
        }
        
        node = head;
        for(int i=0;i<small.size();i++)
        {
            node->val = small[i];
            node = node->next;
        }
        for(int i=0;i<large.size();i++)
        {
            node->val = large[i];
            node = node->next;
        }
        
        return head;
    }
};