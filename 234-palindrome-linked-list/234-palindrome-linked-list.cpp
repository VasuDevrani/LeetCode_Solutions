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
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        
        vector<int>check;
        while(head!=NULL)
        {
            check.push_back(head->val);
            head=head->next;

        }
        int i=0,j=check.size()-1;
        
        while(i<j)
        {
            if(check[i]==check[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }  
        }
        return true;
         
    }
};






