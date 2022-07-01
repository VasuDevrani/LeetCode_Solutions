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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cr, ans;
        
        int prev = head->val;
        head = head->next;
        int i = 2;
        
        while(head->next != NULL)
        {
            if(head->next->val < head->val && head->val > prev)
                cr.push_back(i);
            if(head->next->val > head->val && head->val < prev)
                cr.push_back(i);
            
            prev = head->val;
            head = head->next;
            i++;
        }
        
        if(cr.size() < 2)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            
            return ans;
        }
        
        sort(cr.begin(), cr.end());
        
        int mn = INT_MAX;
        for(int i=0;i<cr.size()-1;i++)
        {
            mn = min(mn, cr[i+1] - cr[i]);
        }
        
        ans.push_back(mn);
        ans.push_back(cr[cr.size()-1] - cr[0]);
        
        return ans;
    }
};