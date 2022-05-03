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
        int l=0;
        while(head!=NULL)
        {
            l++;
            head=head->next;
        }
        return l;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>index;
        stack<int>value;
        index.push(0);
        value.push(head->val);
        
        
        vector<int>ans(length(head),0);
        head=head->next;
        int i=1;
        
        while(head!=NULL)
        {
            while(!value.empty() && head->val>value.top())
            {
                ans[index.top()]=head->val;
                value.pop();
                index.pop();
            }
            value.push(head->val);
            index.push(i);
            i++;   
            head=head->next;
            
        }
        return ans;
    }
};