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
    int getDecimalValue(ListNode* head) {
    
        int num=0;
        string s="";
        while(head!=NULL)
        {
           int x=head->val;
            s+=(char)('0'+x);
            head=head->next;
        }
        cout<<s;
        int p=1;
        int ans=0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            ans+=(p*(int)(s[i]-'0'));
            p=p*2;
        }
        return ans;
    }
};