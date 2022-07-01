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
        vector<int>ans;
        
        int first_ind, prev_ind = 0, last_ind, ct = 0;
        
        int prev = head->val;
        head = head->next;
        int i = 2, mn = INT_MAX;
        
        while(head->next != NULL)
        {
            if((head->next->val < head->val && head->val > prev) || (head->next->val > head->val && head->val < prev))
            {
                if(ct == 0)
                    first_ind = i;
                
                last_ind = i;
                if(ct > 0)
                    mn = min(mn, last_ind - prev_ind);
                
                prev_ind = last_ind;
                    
                ct++;
            }
            
            prev = head->val;
            head = head->next;
            i++;
        }
        if(ct < 2)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        cout<<first_ind<<" "<<last_ind<<" "<<mn;
        
        ans.push_back(mn);
        ans.push_back(last_ind - first_ind);
        
        return ans;
    }
};